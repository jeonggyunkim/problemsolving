#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int bm[510];
bool vis[510];

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

	int tc;
	cin >> tc;

	while (tc--) {
		memset(vis, 0, sizeof(vis));
		edge.clear();

		int h, v;
		cin >> h >> v;

		vector<string> garo(h), sero(v);
		vector<ii> g(h), s(v);
		edge.resize(h);

		for (int i = 0; i < h; ++i) {
			cin >> g[i].first >> g[i].second >> garo[i];
		}
		for (int i = 0; i < v; ++i) {
			cin >> s[i].first >> s[i].second >> sero[i];
		}

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < v; ++j) {
				if (g[i].first <= s[j].first && g[i].first + garo[i].size() - 1 >= s[j].first) {
					if (s[j].second <= g[i].second && s[j].second + sero[j].size() - 1 >= g[i].second) {
						if (garo[i][s[j].first - g[i].first] != sero[j][g[i].second - s[j].second]) {
							edge[i].push_back(j);
						}
					}
				}
			}
		}

		int size = 0;
		memset(bm, -1, sizeof(bm));
		for (int i = 0; i < h; ++i) {
			memset(vis, 0, sizeof(vis));
			if (dfs(i)) size++;
		}

		cout << h + v - size << '\n';
	}
}