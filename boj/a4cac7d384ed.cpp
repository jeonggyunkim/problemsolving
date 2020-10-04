#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int bm[5010];
bool vis[5010];
vector<vector<int>> edge;

bool dfs(int a) {
	if (vis[a]) return 0;
	vis[a] = 1;
	
	for (int b: edge[a]) {
		if (bm[b] == -1 || dfs(bm[b])) {
			bm[b] = a;
			return 1;
		}
	}
	return 0;
}

pair<int, int> board[101][101];
int diag1 = 0, diag2 = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b;
	while (m--) {
		cin >> a >> b;
		board[a][b] = {-1, -1};
	}

	for (int i = 1; i <= n; ++i) {
		for (int x = i, y = 1; x <= n && y <= n; x++, y++) {
			if (board[x][y].first != -1) {
				if (y != 1 && board[x - 1][y - 1].first != -1) {
					board[x][y].first = board[x - 1][y - 1].first;
				}
				else {
					board[x][y].first = diag1++;
				}
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		for (int x = 1, y = i; x <= n && y <= n; x++, y++) {
			if (board[x][y].first != -1) {
				if (x != 1 && board[x - 1][y - 1].first != -1) {
					board[x][y].first = board[x - 1][y - 1].first;
				}
				else {
					board[x][y].first = diag1++;
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int x = i, y = 1; x >= 1 && y <= n; x--, y++) {
			if (board[x][y].second != -1) {
				if (y != 1 && board[x + 1][y - 1].second != -1) {
					board[x][y].second = board[x + 1][y - 1].second;
				}
				else {
					board[x][y].second = diag2++;
				}
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		for (int x = n, y = i; x >= 1 && y <= n; x--, y++) {
			if (board[x][y].second != -1) {
				if (x != n && board[x + 1][y - 1].second != -1) {
					board[x][y].second = board[x + 1][y - 1].second;
				}
				else {
					board[x][y].second = diag2++;
				}
			}
		}
	}

	edge.resize(diag1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (board[i][j].first != -1) {
				edge[board[i][j].first].push_back(board[i][j].second);
			}
		}
	}

	int size = 0;
	memset(bm, -1, sizeof(bm));
	for (int i = 0; i < diag1; ++i) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) size++;
	}

	cout << size;
}