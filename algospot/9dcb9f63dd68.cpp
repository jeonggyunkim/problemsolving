#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int m;
vector<vector<bool>> adj;
vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int a) {
	if (visited[a]) return 0;
	visited[a] = 1;

	for (int b = 0; b < m; ++b) {
		if (adj[a][b]) {
			if (bMatch[b] == -1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int diag1[8][8];
	int diag2[8][8];

	int tc;
	cin >> tc;

	while (tc--) {
		memset(diag1, -1, sizeof(diag1));
		memset(diag2, -1, sizeof(diag2));

		int n;
		cin >> n;

		vector<string> board(n);
		for (int i = 0; i < n; ++i) cin >> board[i];

		int cnt = 0;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			if (board[i][j] == '.') {
				if (i == 0 || j == 0 || board[i - 1][j - 1] == '*') diag1[i][j] = cnt++;
				else diag1[i][j] = diag1[i - 1][j - 1];
			}
		}

		int t = cnt;
		for (int i = 0; i < n; ++i) for (int j = n - 1; j >= 0; --j) {
			if (board[i][j] == '.') {
				if (i == 0 || j == n - 1 || board[i - 1][j + 1] == '*') diag2[i][j] = cnt++;
				else diag2[i][j] = diag2[i - 1][j + 1];
			}
		}

		adj = vector<vector<bool>>(t, vector<bool>(cnt - t, 0));

		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			if (board[i][j] == '.') {
				adj[diag1[i][j]][diag2[i][j] - t] = 1;
			}
		}
		m = cnt - t;

		aMatch = vector<int>(t, -1);
		bMatch = vector<int>(m, -1);

		int size = 0;
		for (int i = 0; i < t; ++i) {
			visited = vector<bool>(t, 0);
			if (dfs(i)) ++size;
		}

		cout << size << '\n';
	}
}
