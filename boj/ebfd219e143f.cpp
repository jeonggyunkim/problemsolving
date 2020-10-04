#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int bm[51];
bool vis[51];
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

	int n;
	cin >> n;

	edge.resize(n);

	int s[51][3];
	for (int i = 0; i < n; ++i) {
		cin >> s[i][0] >> s[i][1] >> s[i][2];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j && s[i][0] >= s[j][0] && s[i][1] >= s[j][1] && s[i][2] >= s[j][2]) {
				if (s[i][0] == s[j][0] && s[i][1] == s[j][1] && s[i][2] == s[j][2])  {
					if  (i > j) edge[i].push_back(j);
				}
				else edge[i].push_back(j);
			}
		}
	}

	int size = 0, Match[50] = {};
	memset(bm, -1, sizeof(bm));
	while (true) {
		bool upd = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; ++i) {
			if (!vis[i] && Match[i] < 2 && dfs(i)) {
				Match[i]++;
				size++;
				upd = 1;
				break;
			}
		}
		if (!upd) break;
	}

	cout << n - size;
}