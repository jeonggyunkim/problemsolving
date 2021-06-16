#include <iostream>
#include <set>
using namespace std;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m;
char board[1001][1001];
bool vis[1001][1001];
int label[1001][1001];
int sz[1001][1001];
int cnt, flag;

void dfs(int i, int j) {
	cnt++;
	vis[i][j] = 1;

	for (int k = 0; k < 4; ++k) {
		int x = i + loc[k][0];
		int y = j + loc[k][1];
		if (x < 0 || x >= n || y < 0 || y >= m) continue;

		if (board[x][y] == '0' && !vis[x][y]) {
			dfs(x, y);
		}
	}
}

void set_size(int i, int j) {
	sz[i][j] = cnt;
	label[i][j] = flag;

	for (int k = 0; k < 4; ++k) {
		int x = i + loc[k][0];
		int y = j + loc[k][1];
		if (x < 0 || x >= n || y < 0 || y >= m) continue;

		if (board[x][y] == '0' && !sz[x][y]) {
			set_size(x, y);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> board[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] != '1' && !sz[i][j]) {
				cnt = 0;
				flag++;
				dfs(i, j);
				set_size(i, j);
			}
		}
	}

	for (int i = 0; i < n ;++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == '1') {
				set<int> st;

				int ans = 1;
				for (int k = 0; k < 4; ++k) {
					int x = i + loc[k][0];
					int y = j + loc[k][1];
					if (x < 0 || x >= n || y < 0 || y >= m) continue;
					if (board[x][y] == '0' && !st.count(label[x][y])) {
						ans += sz[x][y];
						st.insert(label[x][y]);
					}
				}
				cout << ans % 10;
			}
			else cout << "0";
		}
		cout << '\n';
	}
}