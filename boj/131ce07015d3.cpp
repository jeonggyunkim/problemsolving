#include <iostream>
#include <memory.h>
#define INF 987654321
using namespace std;

int n;
int arr[1000];
int dp[1000][1000][2][101];

int cal(int l, int r, int who, int time) {
	int& ref = dp[l][r][who][time];
	if (dp[l][r][who][time] != -1) return ref;
	if (l == r) {
		if (who == 0) return ref = arr[l];
		else return ref = 0;
	}
	
	if (who == 0) {
		ref = 0;
		if (arr[l] <= time) {
			ref = max(ref, cal((l + n - 1) % n, r, who, time - arr[l]) + arr[l]);
		}
		else {
			ref = max(ref, cal((l + n - 1) % n, r, 1 - who, arr[l] - time) + arr[l]);
		}
		if (arr[r] <= time) {
			ref = max(ref, cal(l, (r + 1) % n, who, time - arr[r]) + arr[r]);
		}
		else {
			ref = max(ref, cal(l, (r + 1) % n, 1 - who, arr[r] - time) + arr[r]);
		}
	}
	else {
		ref = INF;
		if (arr[l] < time) {
			ref = min(ref, cal((l + n - 1) % n, r, who, time - arr[l]));
		}
		else {
			ref = min(ref, cal((l + n - 1) % n, r, 1 - who, arr[l] - time));
		}
		if (arr[r] < time) {
			ref = min(ref, cal(l, (r + 1) % n, who, time - arr[r]));
		}
		else {
			ref = min(ref, cal(l, (r + 1) % n, 1 - who, arr[r] - time));
		}
	}
	return ref;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, cal(i, (i + 1) % n, 0, 0));
	}
	cout << ans;
}