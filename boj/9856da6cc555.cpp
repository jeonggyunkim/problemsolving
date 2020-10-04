#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	vector<long long> sum(n + 1, 0), sqsum(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + arr[i - 1];
		sqsum[i] = sqsum[i - 1] + arr[i - 1] * arr[i - 1];
	}

	for (int k = 1; k <= n; ++k) {
		long long maxVar = -1, ans;
		for (int i = k; i <= n; ++i) {
			long long var = k * (sqsum[i] - sqsum[i - k]) - (sum[i] - sum[i - k]) * (sum[i] - sum[i - k]);
			if (var > maxVar) {
				maxVar = var;
				ans = i - k + 1;
			}
		}
		cout << ans << '\n';
	}
}