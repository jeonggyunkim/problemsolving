#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

vector<vector<ii>> edge;
vector<int> depth;
vector<vector<int>> parent;
vector<vector<long long>> dist;
long long ans;

void dfs(int i, int p, int w, int d) {
	depth[i] = d;
	parent[i][0] = p;
	dist[i][0] = w;
	for (int j = 1; j < 18; ++j) {
		if (parent[i][j - 1] != -1) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
			dist[i][j] = dist[i][j - 1] + dist[parent[i][j - 1]][j - 1];
		}
		else break;
	}
	for (ii u : edge[i]) {
		if (u.first != p) {
			dfs(u.first, i, u.second, d + 1);
		}
	}
}

int lca(int a, int b) {
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) swap(a, b);
		int move = depth[b] - depth[a];
		while (move) {
			int t = __builtin_ctz(move);
			ans += dist[b][t];
			b = parent[b][t];
			move &= (move - 1);
		}
	}
	while (a != b) {
		int i = 0;
		while (parent[a][i] != parent[b][i]) i++;
		if (i != 0) i--;
		ans += dist[a][i];
		ans += dist[b][i];
		a = parent[a][i];
		b = parent[b][i];
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	edge.resize(n);
	depth.resize(n);
	parent.resize(n, vector<int>(18, -1));
	dist.resize(n, vector<long long>(18, 0));

	int u, v, w;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v >> w;
		u--; v--;
		edge[u].push_back(ii(v, w));
		edge[v].push_back(ii(u, w));
	}

	dfs(0, -1, 0, 0);

	int q;
	cin >> q;

	int op, a, b, c;
	while (q--) {
		cin >> op >> a >> b;
		a--; b--;
		if (op == 1) {
			ans = 0;
			lca(a, b);
			cout << ans << '\n';
		}
		else {
			cin >> c;
			int d = lca(a, b);
			int da = depth[a] - depth[d];
			int db = depth[b] - depth[d];
			if (c <= da + 1) {
				c--;
				while (c) {
					int t = __builtin_ctz(c);
					a = parent[a][t];
					c &= (c - 1);
				}
				cout << a + 1 << '\n';
			}
			else {
				c = da + db + 1 - c;
				while (c) {
					int t = __builtin_ctz(c);
					b = parent[b][t];
					c &= (c - 1);
				}
				cout << b + 1 << '\n';
			}
		}
	}
}