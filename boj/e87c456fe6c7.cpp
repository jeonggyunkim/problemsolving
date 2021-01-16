#include <iostream>
#include <vector>
using namespace std;

int loc[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int board[302][302];
int ans[302][302];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> board[i][j];
		}
	}

	int x = 1, y = 1;
	while (board[x][y]) {
		int i = x, j = y, dir = 0;
		vector<int> vec;
		while (1) {
			if (!board[i + loc[dir][0]][j + loc[dir][1]]) {
				dir = (dir + 3) % 4;
				if (dir == 0) break;
			}
			vec.push_back(board[i][j]);			
			i += loc[dir][0];
			j += loc[dir][1];
		}

		i = x, j = y, dir = 0;
		for (int ind = 0; ; ++ind) {
			ans[i][j] = vec[(ind + r) % vec.size()];
			board[i][j] = 0;
			if (!board[i + loc[dir][0]][j + loc[dir][1]]) {
				dir = (dir + 3) % 4;
				if (dir == 0) break;
			}
			i += loc[dir][0];
			j += loc[dir][1];
		}
		x++; y++;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}