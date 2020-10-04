#include <iostream>
#include <vector>
using namespace std;

long long ans = 0;
vector<int> d;
vector<vector<int>> edge;

void dfs(int n) {
	bool b = 1;
	for (int u: edge[n]) {
		if (d[u] == -1) {
			b = 0;
			d[u] = d[n] + 1;
			dfs(u);
		}
	}
	if (b) ans += d[n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	edge.resize(n + 1);
	int a, b;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	d.resize(n + 1, -1);
	d[1] = 0;
	dfs(1);

	if (ans & 1) cout << "Yes";
	else cout << "No";
}