#include <iostream>
#include <algorithm>
using namespace std;

int tri[6][3][3], ans;
int board[18], per[6];

void rec(int d) {
	if (d == 6) {
		if (board[17] == board[0]) {
			int now = 0;
			for (int i = 0; i < 6; ++i) now += board[3 * i + 1];
			ans = max(ans, now);
		}
		return;
	}
	for (int i = 0; i < 3; ++i) {
		board[3 * d] = tri[per[d]][i][0];
		board[3 * d + 1] = tri[per[d]][i][1];
		board[3 * d + 2] = tri[per[d]][i][2];
		if (d) {
			if (board[3 * d] != board[3 * d - 1]) continue;
		}
		rec(d + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		ans = -1;
		for (int i = 1; i <= 5; ++i) per[i] = i;

		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 3; ++j) {
				cin >> tri[i][0][j];
			}
			for (int j = 0; j < 3; ++j) {
				tri[i][1][j] = tri[i][0][(j + 1) % 3];
				tri[i][2][j] = tri[i][0][(j + 2) % 3];
			}
		}

		do {
			rec(0);
		} while (next_permutation(per + 1, per + 6));

		if (ans == -1) cout << "none\n";
		else cout << ans << '\n';

		char op;
		cin >> op;
		if (op == '$') break;
	}
}