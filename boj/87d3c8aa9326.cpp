#include <iostream>
#define INF 987654321
using namespace std;

char board[10][11];
int board_mask[11];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; ++i) cin >> board[i];

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (board[i][j] == 'O') board_mask[i] |= (1 << j);
		}
	}

	int ans = INF;
	for (int i = 0; i < (1 << 10); ++i) {
		int mask = board_mask[0];
		int mask_next = board_mask[1];
		int cnt = 0;
		for (int j = 0; j < 10; ++j) {
			if (i & (1 << j)) {
				if (j) mask ^= (1 << (j - 1));
				mask ^= (1 << j);
				mask_next ^= (1 << j);
				if (j != 9) mask ^= (1 << (j + 1));
				cnt++;
			}
		}

		for (int j = 0; j < 9; ++j) {
			int rev = mask;
			mask = mask_next;
			mask_next = board_mask[j + 2];

			for (int k = 0; k < 10; ++k) {
				if (rev & (1 << k)) {
					if (k) mask ^= (1 << (k - 1));
					mask ^= (1 << k);
					mask_next ^= (1 << k);
					if (k != 9) mask ^= (1 << (k + 1));
					cnt++;
				}
			}
		}

		if (mask == 0) {
			ans = min(ans, cnt);
		}
	}

	if (ans == INF) cout << -1;
	else cout << ans;
}