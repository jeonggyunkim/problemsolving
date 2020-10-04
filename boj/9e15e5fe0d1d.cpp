#include <iostream>
#include <vector>
using namespace std;

int parent[100010][18];
int depth[100010];
vector<vector<int>> edge;

void dfs(int i, int p, int d) {
	parent[i][0] = p;
	depth[i] = d;
	for (int j = 1; j < 18; ++j) {
		parent[i][j] = parent[parent[i][j - 1]][j - 1];
	}
	for (int u: edge[i]) {
		if (u != p) {
			dfs(u, i, d + 1);
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int inc = depth[a] - depth[b];
	for (int i = 0; i < 18; ++i) {
		if (inc & (1 << i)) a = parent[a][i];
	}
	if (a == b) return a;
	for (int i = 17; i >= 0; --i) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

int nth_parent(int a, int n) {
	for (int i = 17; i >= 0; --i) {
		if (n & (1 << i)) a = parent[a][i];
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	edge.resize(n + 1);

	int a, b, c;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(1, 0, 0);

	int q;
	cin >> q;

	while (q--) {
		cin >> a >> b >> c;
		if (depth[a] < depth[b]) swap(a, b);
		int lcaAB = lca(a, b);
		int distAB = depth[a] + depth[b] - 2 * depth[lcaAB];
		if (distAB & 1) {
			cout << "-1\n";
			continue;
		}
		int mid;
		if (depth[a] > depth[b]) mid = nth_parent(a, distAB / 2);
		else mid = nth_parent(b, distAB / 2);

		if (mid == lcaAB) {
			int d = lca(c, mid);
			if (d == mid) {
				if (depth[a] - depth[mid] == depth[c] - depth[mid]) {
					cout << mid << '\n';
					continue;
				}
				if (lca(a, c) == mid && lca(b, c) == mid) {
					int distMC = depth[c] - depth[mid];
					if ((distAB / 2 + distMC) & 1 || distMC < distAB / 2) cout << "-1\n";
					else {
						cout << nth_parent(c, distMC - (distMC - distAB / 2) / 2) << '\n';
					}
				}
				else cout << "-1\n";
			}
			else {
				int distMC = depth[mid] + depth[c] - 2 * depth[d];
				if ((distMC + distAB / 2) & 1 || distMC < distAB / 2) cout << "-1\n";
				else {
					int move = (distMC - distAB / 2) / 2;
					if (depth[mid] - depth[d] >= move) cout << nth_parent(mid, move) << '\n';
					else cout << nth_parent(c, distMC - move) << '\n';
				}
			}
		}
		else {
			int d = lca(c, mid);
			int distMC = depth[mid] + depth[c] - 2 * depth[d];
			if (distMC == distAB / 2) {
				cout << mid << '\n';
				continue;
			}
			if (d == mid) {
				if (lca(a, c) != mid) cout << "-1\n";
				else {
					if ((distMC + distAB / 2) & 1 || distMC < distAB / 2) cout << "-1\n";
					else cout << nth_parent(c, distMC - (distMC - distAB / 2) / 2) << '\n';
				}
			}
			else cout << "-1\n";
		}
	}	
}