#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int board[64][64];
	bool can[64][64] = {};

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> board[i][j];

	can[0][0] = 1;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (can[i][j]) {
			if (i + board[i][j] < n) can[i + board[i][j]][j] = 1;
			if (j + board[i][j] < n) can[i][j + board[i][j]] = 1;
		}
	}

	if (can[n - 1][n - 1]) cout << "HaruHaru";
	else cout << "Hing";
}