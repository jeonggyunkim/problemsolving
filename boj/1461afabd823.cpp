#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<int> subd;
int D;
int ans;

int dfs(int p, int i, int d) {
	int ret = d;
	for (int u: edge[i]) {
		if (u != p) ret = max(ret, dfs(i, u, d + 1));
	}
	return subd[i] = ret;
}

void dfs2(int p, int i, int d) {
	for (int u: edge[i]) {
		if (u != p) {
			if (subd[u] - d > D) {
				ans++;
				dfs2(i, u, d + 1);
				ans++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s >> D;
	s--;
	edge.resize(n);
	subd.resize(n);

	int a, b;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(-1, s, 0);
	if (subd[s] > D) dfs2(-1, s, 0);
	cout << ans;
}
