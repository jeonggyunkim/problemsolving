#include <iostream>
using namespace std;

int f[200000][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, q;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		cin >> f[i][0];
		f[i][0]--;
	}
	for (int i = 1; i < 20; ++i) {
		for (int j = 0; j < m; ++j) {
			f[j][i] = f[f[j][i - 1]][i - 1];
		}
	}

	cin >> q;

	int n, x;
	while (q--) {
		cin >> n >> x;
		x--;
		
		for (int i = 0; i < 20; ++i) {
			if (n & (1 << i)) {
				x = f[x][i];
			}
		}
		cout << x + 1 << '\n';
	}
}