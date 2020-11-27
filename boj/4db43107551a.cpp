#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int parent[100010][18];
int dist[100010][18];
vector<vector<ii>> edge;

void dfs(int i, int p) {
	for (int j = 1; j < 18; ++j) {
		parent[i][j] = parent[parent[i][j - 1]][j - 1];
		dist[i][j] = dist[parent[i][j - 1]][j - 1] + dist[i][j - 1];
	}
	for (ii u: edge[i]) {
		if (u.first != p) {
			parent[u.first][0] = i;
			dist[u.first][0] = u.second;
			dfs(u.first, i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	edge.resize(n + 1);

	vector<int> ant(n);
	for (int i = 0; i < n; ++i) cin >> ant[i];

	int a, b, c;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b >> c;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}

	dfs(1, 0);

	for (int i = 0; i < n; ++i) {
		int now = i + 1, w = ant[i];
		while (1) {
			int up = -1;
			for (int j = 0; j < 18; ++j) {
				if (dist[now][j] > w) break;
				else {
					up = j;
				}
			}
			if (now <= 1 || up == -1) break;
			w -= dist[now][up];
			now = parent[now][up];
		}
		if (now) cout << now << '\n';
		else cout << 1 << '\n';
	}
}