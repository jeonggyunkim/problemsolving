#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
bool vis[200000];
vector<vector<int>> edge;

int dfs(int i) {
	int ret = 1;
	vis[i] = 1;
	for (int u: edge[i]) {
		if (!vis[u]) ret += dfs(u);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	edge.resize(n);

	while (m--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	long long ans = 1;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			ans *= dfs(i);
			ans %= MOD;
		}
	}
	cout << ans << '\n';
}