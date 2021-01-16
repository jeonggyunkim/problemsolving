#include <iostream>
using namespace std;

char mine[10][11];
char board[10][11];



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> mine[i];
	for (int i = 0; i < n; ++i) cin >> board[i];

	bool die = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 'x' && mine[i][j] == '*') {
				die = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 'x') {
				if (mine[i][j] == '*') {
					cout << '*';
					continue;
				}
				int cnt = 0;
				for (int ii = -1; ii <= 1; ++ii) {
					for (int jj = -1; jj <= 1; ++jj) {
						if (ii || jj) {
							if (i + ii < 0 || i + ii >= n || j + jj < 0 || j + jj >= n) continue;
							if (mine[i + ii][j + jj] == '*') cnt++;
						}
					}
				}
				cout << cnt;
			}
			else {
				if (die && mine[i][j] == '*') cout << '*';
				else cout << '.';
			}
		}
		cout << '\n';
	}
}