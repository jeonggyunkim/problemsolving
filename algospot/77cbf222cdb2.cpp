#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#define large (1LL << 32)
using namespace std;

typedef tuple<int, int, long long> iii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int arr[501] = {}, n, k;
		int dp[501] = {};
		long long cnt[501] = {};
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) cin >> arr[i];

		dp[n] = 1; cnt[n] = 1;
		for (int i = n - 1; i > 0; --i) {
			int max = 0;
			for (int j = i + 1; j <= n; ++j) if (arr[j] > arr[i] && dp[j] > max) max = dp[j];
			dp[i] = max + 1;
			if (dp[i] == 1) cnt[i] = 1;
			else {
				for (int j = i + 1; j <= n; ++j) if (arr[j] > arr[i] && dp[j] == max) {
					cnt[i] += cnt[j];
					if (cnt[i] >= large) cnt[i] = large;
				}
			}
		}

		int max = 0;
		for (int i = 1; i <= n; ++i) if (dp[i] > max) max = dp[i];

		cout << max << '\n';
		int start = 0;
		while (max) {
			vector<iii> v;
			for (int i = start + 1; i <= n; ++i) if (dp[i] == max && arr[i] > arr[start]) v.push_back(iii(arr[i], i, cnt[i]) );

			sort(v.begin(), v.end());

			int i = -1;
			long long sum = 0;
			do { ++i; sum += get<2>(v[i]); } while (i < v.size() && sum < k);

			start = get<1>(v[i]);
			for (int j = 0; j < i; ++j) k -= get<2>(v[j]);

			cout << get<0>(v[i]) << ' ';
			max--;
		}
		cout << '\n';
	}
}
