#include <iostream>
#include <memory.h>
#define INF 987654321
using namespace std;

int dp[10010][3];
int arr[10010][2];
int n, w, f;

int d(int x, int stat) {
	if (dp[x][stat] != -1) return dp[x][stat];
	if (f == 0 && x == n && stat == 0) return 0;
	else if (f == 1 && x == n - 1 && stat == 2) return 0;
	else if (f == 2 && x == n - 1 && stat == 1) return 0;
	else if (f == 3 && x == n - 1 && stat == 0) return 0;

	int ret = INF;
	if (stat == 0) {
		if (x <= n - 2 || (x == n - 1 && (f % 2 == 0))) ret = min(ret, d(x, 1) + 1);
		if (x <= n - 2 || (x == n - 1 && f < 2)) ret = min(ret, d(x, 2) + 1);
		if (x <= n - 2 || (x == n - 1 && f == 0)) {
			if (arr[x][0] + arr[x][1] <= w) ret = min(ret, d(x + 1, 0) + 1);
		}
		if (x <= n - 3 || (x == n - 2 && f == 0)) {
			if (arr[x][0] + arr[x + 1][0] <= w && arr[x][1] + arr[x + 1][1] <= w) ret = min(ret, d(x + 2, 0) + 2);
		}
	}
	else if (stat == 1) {
		ret = min(ret, d(x + 1, 0) + 1);
		if (x <= n - 3 || (x == n - 2 && f < 2)) {
			if (arr[x][1] + arr[x + 1][1] <= w) ret = min(ret, d(x + 1, 2) + 1);
		}
	}
	else {
		ret = min(ret, d(x + 1, 0) + 1);
		if (x <= n - 3 || (x == n - 2 && (f % 2 == 0))) {
			if (arr[x][0] + arr[x + 1][0] <= w) ret = min(ret, d(x + 1, 1) + 1);
		}
	}
	return dp[x][stat] = ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		cin >> n >> w;

		for (int i = 0; i < n; ++i) cin >> arr[i][1];
		for (int i = 0; i < n; ++i) cin >> arr[i][0];

		int ans = INF;
		memset(dp, -1, sizeof(dp));
		f = 0; ans = min(ans, d(0, 0));
		if (arr[0][0] + arr[n - 1][0] <= w) {
			memset(dp, -1, sizeof(dp));
			f = 1;
			ans = min(ans, d(0, 1) + 1);
		}
		if (arr[0][1] + arr[n - 1][1] <= w) {
			memset(dp, -1, sizeof(dp));
			f = 2;
			ans = min(ans, d(0, 2) + 1);
		}
		if (arr[0][0] + arr[n - 1][0] <= w && arr[0][1] + arr[n - 1][1] <= w) {
			memset(dp, -1, sizeof(dp));
			f = 3;
			ans = min(ans, d(1, 0) + 2);
		}
		cout << ans << '\n';
	}
}