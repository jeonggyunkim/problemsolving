#include <iostream>
using namespace std;

int main() {
	int ans = -1;
	for (int n = 2; n <= 9; ++n) {
		int p = 1;
		for (int i = 0; i < 9 / n; ++i) p *= 10;
		for (int i = 1; i < p; ++i) {
			int cnt[10] = {};
			for (int j = 1; j <= n; ++j) {
				int k = i * j;
				while (k) {
					cnt[k % 10]++;
					k /= 10;
				}
			}
			bool pos = 1;
			for (int j = 1; j <= 9; ++j) {
				if (cnt[j] != 1) pos = 0;
			}
			if (pos) {
				int concat = 0;
				for (int j = 1; j <= n; ++j) {
					int k = i * j;
					int p = 1;
					while (p <= k) p *= 10;
					concat *= p;
					concat += k;
				}
				ans = max(ans, concat);
			}
		}
	}
	cout << ans << endl;
}