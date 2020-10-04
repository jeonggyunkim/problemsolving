#include <iostream>
#define MOD 10000000
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int poly[101][101] = {};
	poly[1][1] = 1;

	for (int i = 2; i <= 100; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i == j) {
				poly[i][j] = 1;
				continue;
			}
			int r = 0;
			for (int k = 1; k <= (i - j); ++k) {
				r += (j + k - 1) * poly[i - j][k];
				r %= MOD;
			}
			poly[i][j] = r;
		}
	}

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		int r = 0;
		for (int i = 1; i <= n; ++i) {
			r += poly[n][i];
			r %= MOD;
		}
		cout << r << '\n';
	}
}
