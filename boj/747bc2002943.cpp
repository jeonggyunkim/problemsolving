#include <iostream>
#include <vector>
#include <memory.h>
#define SQ(a) ((a) * (a))
using namespace std;

typedef pair<double, double> dd;

int bm[110];
bool vis[110];
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

double dist(dd a, dd b) {
	return SQ(a.first - b.first) + SQ(a.second - b.second);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, s, v;
	cin >> n >> m >> s >> v;
	edge.resize(n);

	double x, y;
	vector<dd> mouse(n), hole(m);
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		mouse[i] = {x, y};
	}

	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		hole[i] = {x, y};
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dist(mouse[i], hole[j]) <= SQ(s * v)) {
				edge[i].push_back(j);
			}
		}
	}

	int size = 0;
	memset(bm, -1, sizeof(bm));
	for (int i = 0; i < n; ++i) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) size++;
	}

	cout << n - size;
}