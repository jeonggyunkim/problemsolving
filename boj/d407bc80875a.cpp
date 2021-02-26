#include <iostream>
using namespace std;

string board[1000];
char flag[2][2];

int match[1000][1000][3];

static int num(char a) {
	if (a == 'J') return 0;
	else if (a == 'O') return 1;
	else return 2;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> board[i];
	cin >> flag[0] >> flag[1];


	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			int cnt = 0;
			if (board[i][j] == flag[0][0]) cnt += 1;
			if (board[i][j + 1] == flag[0][1]) cnt += 2;
			if (board[i + 1][j] == flag[1][0]) cnt += 4;
			if (board[i + 1][j + 1] == flag[1][1]) cnt += 8;

			if (cnt == 15) {
				ans++;
				for (int k = 0; k < 3; ++k) {
					if (num(board[i][j]) != k) match[i][j][k]--;
					if (num(board[i][j + 1]) != k) match[i][j + 1][k]--;
					if (num(board[i + 1][j]) != k) match[i + 1][j][k]--;
					if (num(board[i + 1][j + 1]) != k) match[i + 1][j + 1][k]--;
				}
			}
			else if (__builtin_popcount(cnt) == 3) {
				if (15 - cnt == 1) match[i][j][num(flag[0][0])]++;
				else if (15 - cnt == 2) match[i][j + 1][num(flag[0][1])]++;
				else if (15 - cnt == 4) match[i + 1][j][num(flag[1][0])]++;
				else if (15 - cnt == 8) match[i + 1][j + 1][num(flag[1][1])]++;
			}
		}
	}

	int mx = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < 3; ++k) {
				mx = max(mx, match[i][j][k]);
			}
		}
	}
	cout << ans + mx;
}