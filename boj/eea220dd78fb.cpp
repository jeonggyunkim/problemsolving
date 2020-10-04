#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int l, board[300][300];
		cin >> l;
		memset(board, -1, sizeof(board));

		int x, y;
		cin >> x >> y;
		board[x][y] = 0;
		queue<ii> q;
		q.push(ii(x, y));
		while (!q.empty()) {
			ii t = q.front(); q.pop();
			for (int i = 0; i < 8; ++i) {
				x = t.first + dx[i];
				y = t.second + dy[i];
				if (x < 0 || x >= l || y < 0 || y >= l) continue;
				if (board[x][y] == -1) {
					board[x][y] = board[t.first][t.second] + 1;
					q.push(ii(x, y));
				}
			}
		}

		cin >> x >> y;
		cout << board[x][y] << '\n';
	}
}