#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	vector<long long> sum(n + 1);
	sum[0] = 0;
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + arr[i];
	}

	long long ans = sum[n] + 1;
	int ansk = n / 2;

	for (int k = n / 2; k >= 1; --k) {
		multiset<long long> ms;
		for (int i = 1 + k; i <= n - k + 1; ++i) ms.insert(sum[i + k - 1] - sum[i - 1]);


		for (int i = 1; i <= n - 2 * k + 1; ++i) {
			long long t = sum[i + k - 1] - sum[i - 1];

			auto it = ms.lower_bound(t);
			if (it != ms.end()) {
				long long now = abs(t - *it);
				if (now < ans) {
					ans = now;
					ansk = k;
				}
			}
			if (it != ms.begin()) {
				it--;
				long long now = abs(t - *it);
				if (now < ans) {
					ans = now;
					ansk = k;
				}
			}

			it = ms.find(sum[i + 2 * k - 1] - sum[i + k - 1]);
			ms.erase(it);
		}
	}

	cout << ansk << '\n' << ans;
}