#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int near[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int a, b;
vector<vector<bool>> adj;
vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int i) {
	if (visited[i]) return 0;
	visited[i] = 1;

	for (int j = 0; j < b; ++j) {
		if (adj[i][j]) {
			if (bMatch[j] == -1 || dfs(bMatch[j])) {
				aMatch[i] = j;
				bMatch[j] = i;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char board[22][22];
	int numbering[22][22];

	int tc;
	cin >> tc;

	while (tc--) {
		int h, w;
		cin >> h >> w;

		memset(numbering, -1, sizeof(numbering));
		for (int i = 0; i < h; ++i) cin >> board[i];

		a = b = 0;
		int cnt = 0;
		for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
			if (board[i][j] == '.') cnt++;
			if (((i + j) & 1) && board[i][j] == '.') numbering[i][j] = a++;
		}

		for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
			if (((i + j) & 1) == 0 && board[i][j] == '.') numbering[i][j] = a + b++;
		}

		adj = vector<vector<bool>>(a, vector<bool>(b, 0));
		for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
			if (((i + j) & 1) && board[i][j] == '.') {
				for (int k = 0; k < 4; ++k) {
					if (i + near[k][0] < 0 || i + near[k][0] >= h) continue;
					if (j + near[k][1] < 0 || j + near[k][1] >= w) continue;
					if (numbering[i + near[k][0]][j + near[k][1]] != -1) {
						adj[numbering[i][j]][numbering[i + near[k][0]][j + near[k][1]] - a] = 1;
					}
				}
			}
		}

		aMatch = vector<int>(a, -1);
		bMatch = vector<int>(b, -1);

		int size = 0;
		for (int i = 0; i < a; ++i) {
			visited = vector<bool>(a, 0);
			if (dfs(i)) ++size;
		}

		vector<bool> aChosen(a, 1);
		vector<bool> bChosen(b, 0);

		for (int i = 0; i < b; ++i) if (bMatch[i] == -1) bChosen[i] = 1;

		while (true) {
			bool change = 0;
			for (int i = 0; i < a; ++i) for (int j = 0; j < b; ++j) {
				if (aChosen[i] && bChosen[j] && adj[i][j]) {
					aChosen[i] = 0;
					bChosen[aMatch[i]] = 1;
					change = 1;
				}
			}
			if (!change) break;
		}

		for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
			if (numbering[i][j] != -1) {
				int t = numbering[i][j];
				if (t < a) {
					if (aChosen[t]) board[i][j] = '^';
				}
				else {
					if (bChosen[t - a]) board[i][j] = '^';
				}
			}
		}

		cout << cnt - size << '\n';
		for (int i = 0; i < h; ++i) cout << board[i] << '\n';
	}
}
