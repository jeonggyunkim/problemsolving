#include <iostream>
using namespace std;

int n, m;
int interest[15][4];
int yeon[15][2];
int tong[120][3];
int now[16];

void rec(int f) {
	if (f == n) {
		for (int i = 0; i < m; ++i) {
			int jj = tong[i][2] - 1;
			if (interest[now[tong[i][0]] - 1][jj] != interest[now[tong[i][1]] - 1][jj]) {
				return;
			}
		}
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) cout << now[i] << ' ';
		exit(0);
	}
	if (!now[yeon[f][0]]) {
		now[yeon[f][0]] = f + 1;
		rec(f + 1);
		now[yeon[f][0]] = 0;
	}
	if (yeon[f][0] != yeon[f][1] && !now[yeon[f][1]]) {
		now[yeon[f][1]] = f + 1;
		rec(f + 1);
		now[yeon[f][1]] = 0;
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) cin >> interest[i][j];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) cin >> yeon[i][j];
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 3; ++j) cin >> tong[i][j];
	}

	rec(0);
	cout << "NO";
}