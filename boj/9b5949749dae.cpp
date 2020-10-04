#include <iostream>
#include <memory.h>
#define INF 987654321
using namespace std;

bool board[18][18];

int loc[5][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	int ans = INF;
	for (int init = 0; init < (1 << n); ++init) {
		bool now[18][18];
		memcpy(now, board, sizeof(board));
		int b = 0;
		for (int i = 0; i < n; ++i) {
			if ((1 << i) & init) {
				b++;
				for (int k = 0; k < 5; ++k) {
					int x = loc[k][0];
					int y = i + loc[k][1];
					if (x < 0 || x >= n || y < 0 || y >= n) continue;
					now[x][y] = !now[x][y];
				}
			}
		}

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (now[i - 1][j]) {
					b++;
					for (int k = 0; k < 5; ++k) {
						int x = i + loc[k][0];
						int y = j + loc[k][1];
						if (x < 0 || x >= n || y < 0 || y >= n) continue;
						now[x][y] = !now[x][y];
					}
				}
			}
		}

		bool pos = 1;
		for (int i = 0; i < n; ++i) {
			if (now[n - 1][i]) {
				pos = 0;
				break;
			}
		}

		if (pos) ans = min(ans, b);
	}
	
	if (ans == INF) cout << -1;
	else cout << ans;
}
