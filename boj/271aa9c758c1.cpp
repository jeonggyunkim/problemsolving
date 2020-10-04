#include <iostream>
using namespace std;

int a[20][20], b[20][20], c[20][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, p, q;
	int test = 1;
	while (cin >> m >> n >> p >> q, m) {
		cout << "Case #" << test++ << ":\n";
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < p; ++i) {
			for (int j = 0; j < q; ++j) {
				cin >> b[i][j];
			}
		}
		if (n != p) cout << "undefined\n";
		else {
			for (int i = 0; i < m; ++i) {
				cout << "| ";
				for (int j = 0; j < q; ++j) {
					c[i][j] = 0;
					for (int k = 0; k < n; ++k) c[i][j] += a[i][k] * b[k][j];
					cout << c[i][j] << ' ';
				}
				cout << "|\n";
			}
		}
	}
}