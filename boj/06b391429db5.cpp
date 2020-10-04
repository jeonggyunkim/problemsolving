#include <iostream>
#include <string>
using namespace std;

string s[1010];
int vis[1010][1010];
int cnt = 0;

void dfs(int i, int j) {
	if (vis[i][j] == 2) return;
	else if (vis[i][j] == 1) {
		cnt++;
		return;
	}
	vis[i][j] = 1;
	if (s[i][j] == 'L') dfs(i, j - 1);
	if (s[i][j] == 'R') dfs(i, j + 1);
	if (s[i][j] == 'U') dfs(i - 1, j);
	if (s[i][j] == 'D') dfs(i + 1, j);
	vis[i][j] = 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0 ; j < m; ++j) {
			if (!vis[i][j]) dfs(i, j);
		}
	}

	cout << cnt;
}