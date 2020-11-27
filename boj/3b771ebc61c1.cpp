#include <iostream>
using namespace std;

int board[36][36];

int loc[36][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n, nn;
		cin >> n;
		nn = n * n;

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				loc[cnt][0] = i;
				loc[cnt][1] = j;
				cnt++;
			}
		}

		int pos = 1;
		for (int i = 0; i < nn; ++i) {
			for (int j = 0; j < nn; ++j) {
				cin >> board[i][j];
				if (board[i][j] < 0 || board[i][j] > nn) pos = 0;
			}
		}

		for (int i = 0; i < nn; ++i) {
			for (int j = 0; j < nn; ++j) {
				for (int k = j + 1; k < nn; ++k) {
					if (board[i][j] == board[i][k]) pos = 0;
					if (board[j][i] == board[k][i]) pos = 0;
				}
			}
		}

		for (int i = 0; i < nn; i += n) {
			for (int j = 0; j < nn; j += n) {
				for (int k = 0; k < nn; ++k) {
					for (int l = k + 1; l < nn; ++l) {
						if (board[i + loc[k][0]][j + loc[k][1]] == board[i + loc[l][0]][j + loc[l][1]]) pos = 0;
					}
				}
			}
		}

		cout << "Case #" << test << ": " << (pos ? "Yes" : "No") << '\n';
	}
}