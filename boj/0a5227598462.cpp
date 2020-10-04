#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		
		int cnt[1000] = {};
		char t;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				cin >> t;
				if (t == '1') {
					cnt[i]++;
					cnt[j]++;
				}
			}
		}

		int total = n * (n - 1) * (n - 2) / 6;
		int comb = 0;

		for (int i = 0; i < n; ++i) {
			comb += cnt[i] * (n - 1 - cnt[i]);
		}

		cout << total - comb / 2 << '\n';
	}
}