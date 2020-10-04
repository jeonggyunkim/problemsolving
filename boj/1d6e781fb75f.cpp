#include <iostream>
using namespace std;

char board[101][101];
bool b[101][101];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> board[i];

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!b[i][j]) {
				ans++;
				if (board[i][j] == '-') {
					int k = j;
					while (k < m && board[i][k] == '-') {
						b[i][k] = 1;
						k++;
					}
				}
				else {
					int k = i;
					while (k < n && board[k][j] == '|') {
						b[k][j] = 1;
						k++;
					}
				}
			}
		}
	}
	cout << ans;
}