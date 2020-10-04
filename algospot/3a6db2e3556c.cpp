#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int com[201][201] = {};
	for (int i = 0; i <= 200; ++i) {
		com[i][0] = 1;
	}
	for (int i = 1; i <= 200; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (com[i - 1][j - 1] + com[i - 1][j] > 1000000005) {
				com[i][j] = 1000000005;
			}
			else {
				com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
			}
		}
	}

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m, k, p;
		cin >> n >> m >> k;

		p = m + n;
		while (p != 0) {
			if (k <= com[p - 1][m]) {
				cout << '-';
				p--;
			}
			else {
				cout << 'o';
				k -= com[p - 1][m];
				p--; m--;
			}
		}
		cout << '\n';
	}
}
