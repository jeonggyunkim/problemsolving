#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edge;
vector<int> visited;
bool ans;

void dfs(int n) {
	for (int u: edge[n]) {
		if (visited[u] == 0) {
			visited[u] = 3 - visited[n];
			dfs(u);
		}
		else if (visited[u] == visited[n]) ans = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	for (int test = 1; test <= tc; ++test) {
		int n, m;
		cin >> n >> m;
		edge.clear();
		edge.resize(n + 1);
		visited.clear();
		visited.resize(n + 1, 0);
		ans = true;
		int a, b;
		while (m--) {
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		
		for (int i = 1; i <= n; ++i) if (visited[i] == 0) {
			visited[i] = 1;
			dfs(i);
		}
		cout << "Case #" << test << '\n';
		if (ans == true) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}