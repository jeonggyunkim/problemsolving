#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef pair<long long, long long> ii;

ii arr[300];
int dp[300][300];

int domino(int l, int r) {
	if (r < l) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	int now = 987654321;
	for (int i = l; i <= r; ++i) {
		long long mx = arr[i].first + arr[i].second;
		int j = i + 1;
		while (j <= r && arr[j].first <= mx) {
			mx = max(mx, arr[j].first + arr[j].second);
			j++;
		}
		now = min(now, domino(l, i - 1) + domino(j, r) + 1);
	}
	for (int i = l; i <= r; ++i) {
		long long mx = arr[i].first - arr[i].second;
		int j = i - 1;
		while (j >= l && arr[j].first >= mx) {
			mx = min(mx, arr[j].first - arr[j].second);
			j--;
		}
		now = min(now, domino(l, j) + domino(i + 1, r) + 1);
	}
	return dp[l][r] = now;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);

	cout << domino(0, n - 1);
}