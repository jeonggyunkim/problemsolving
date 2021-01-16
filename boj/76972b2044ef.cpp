#include <iostream>
using namespace std;

int n, d;
int board[500][500];

void cw() {
	for (int i = 0; i < n / 2; ++i) {
		swap(board[i][i], board[i][n / 2]);
		swap(board[n / 2][i], board[i][i]);
		swap(board[n - 1 - i][i], board[n / 2][i]);
		swap(board[n - 1 - i][n / 2], board[n - 1 - i][i]);
		swap(board[n - 1 - i][n - 1 - i], board[n - 1 - i][n / 2]);
		swap(board[n / 2][n - 1 - i], board[n - 1 - i][n - 1 - i]);
		swap(board[i][n - 1 - i], board[n / 2][n - 1 - i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;

	while (tc--) {
		cin >> n >> d;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> board[i][j];
			}
		}

		if (d < 0) d += 360;
		while (d > 0) {
			cw();
			d -= 45;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}