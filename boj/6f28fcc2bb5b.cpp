#include <iostream>
using namespace std;

int loc[6][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}};

int board[6][6];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 6; ++j) {
				cin >> board[i][j];
			}
		}

		int pos = 1;
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 6; ++j) {
				for (int k = j + 1; k < 6; ++k) {
					if (board[i][j] == board[i][k]) pos = 0;
					if (board[j][i] == board[k][i]) pos = 0;
				}
			}
		}

		for (int i = 0; i < 6; i += 2) {
			for (int j = 0; j < 6; j += 3) {
				for (int k = 0; k < 6; ++k) {
					for (int l = k + 1; l < 6; ++l) {
						if (board[i + loc[k][0]][j + loc[k][1]] == board[i + loc[l][0]][j + loc[l][1]]) pos = 0;
					}
				}
			}
		}

		for (int i = 0; i < 6; ++i) {
			for (int j = i + 1; j < 6; ++j) {
				if (board[i][i] == board[j][j]) pos = 0;
				if (board[i][5 - i] == board[j][5 - j]) pos = 0;
			}
		}

		cout << "Case#" << test << ": " << pos << '\n';
	}
}