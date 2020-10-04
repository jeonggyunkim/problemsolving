#include <iostream>
#include <algorithm>
#define INF (1LL << 60)
using namespace std;

int arr[1010];
long long dp[1010][1010];
int a[1010][1010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) cin >> arr[i];
	sort(arr + 1, arr + m + 1);
	arr[m + 1] = n;

	for (int i = 0; i < m; ++i) {
		dp[i][i + 2] = arr[i + 2] - arr[i];
		a[i][i + 2] = i + 1;
	}
	for (int j = 3; j <= m + 1; ++j) {
		for (int i = j - 3; i >= 0; --i) {
			dp[i][j] = INF;
			for (int k = a[i][j - 1]; k <= a[i + 1][j]; ++k) {
				int v = dp[i][k] + dp[k][j] + arr[j] - arr[i];
				if (v < dp[i][j]) {
					dp[i][j] = v;
					a[i][j] = k;
				}
			}
		}
	}


	cout << dp[0][m + 1];
}