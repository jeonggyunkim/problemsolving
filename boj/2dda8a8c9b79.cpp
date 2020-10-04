#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int n;
vector<vector<int>> adj;
vector<int> visit;
vector<ii> cut;
int counter = 0;

int dfs(int i, int p) {
	visit[i] = counter++;

	int ret = INF;
	for (int u: adj[i]) {
		if (visit[u] == -1) {
			int r = dfs(u, i);
			if (r > visit[i]) {
				if (i > u) cut.push_back(ii(u, i));
				else cut.push_back(ii(i, u));
			}
			ret = min(ret, r);
		}
		else {
			if (u != p) ret = min(ret, visit[u]);
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m;

	adj.resize(n + 1);
	visit.resize(n + 1, -1);

	int a, b;
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);

	sort(cut.begin(), cut.end());
	cout << cut.size() << '\n';
	for (int i = 0; i < cut.size(); ++i) {
		cout << cut[i].first << ' ' << cut[i].second << '\n';
	}
}