#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int bm[1300];
bool vis[1300];
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	char board[51][51];
	int bn[51][51];

	int counter = -1;
	bool con = 0;
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == '*') {
				if (con) bn[i][j] = counter;
				else {
					bn[i][j] = ++counter;
					con = 1;
				}
			}
			else con = 0;
		}
		con = 0;
	}

	edge.resize(counter + 1);
	counter = -1;
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (board[i][j] == '*') {
				if (con) edge[bn[i][j]].push_back(counter);
				else {
					edge[bn[i][j]].push_back(++counter);
					con = 1;
				}
			}
			else con = 0;
		}
		con = 0;
	}

	int ans = 0;
	memset(bm, -1, sizeof(bm));
	for (int i = 0; i < edge.size(); ++i) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) ans++;
	}

	cout << ans;
}