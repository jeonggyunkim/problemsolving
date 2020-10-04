#include <iostream>
using namespace std;

char board[4][5];

int main() {
	for (int i = 0; i < 4; ++i) cin >> board[i];

	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (board[i][j] != '.') {
				int x = (board[i][j] - 'A') / 4;
				int y = (board[i][j] - 'A') % 4;
				ans += abs(x - i) + abs(y - j);
			}
		}
	}
	cout << ans;
}