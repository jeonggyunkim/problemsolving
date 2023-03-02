#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

vector<vector<int>> edge;
int dist[10000], p[10000];
vector<int> ans;

void get_ans(int a, int b) {
	while (a != b) {
		if (dist[a] != dist[b]) {
			if (dist[a] > dist[b]) {
				ans.push_back(a);
				a = p[a];
			}
			else {
				ans.push_back(b);
				b = p[b];
			}
		}
		else {
			ans.push_back(a);
			ans.push_back(b);
			a = p[a];
			b = p[b];
		}
	}
	ans.push_back(a);
}

void dfs(int i, int par) {
	for (int u: edge[i]) {
		if (u == par) continue;
		if (dist[u] == -1) {
			dist[u] = dist[i] + 1;
			p[u] = i;
			dfs(u, i);
		}
		else {
			if (ans.empty()) get_ans(u, i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n;

	edge.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	memset(dist, -1, sizeof(dist));
	memset(p, -1, sizeof(p));

	dist[0] = 0;
	dfs(0, -1);
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int u: ans) cout << u + 1 << ' ';
}