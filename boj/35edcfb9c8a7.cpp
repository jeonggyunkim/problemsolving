#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> edge;
int color[100010];
int ans = 987654321;

void dfs(int i, int p, int d, map<int, int>& mp) {
	for (int u: edge[i]) {
		if (u != p) {
			map<int, int> now;
			dfs(u, i, d + 1, now);
			if (now.size() > mp.size()) swap(mp, now);

			for (auto u: now) {
				if (mp.count(u.first)) {
					ans = min(ans, mp[u.first] - d + u.second - d);
					mp[u.first] = min(u.second, mp[u.first]);
				}
				else mp[u.first] = u.second;
			}
		}
	}
	if (mp.count(color[i])) ans = min(ans, mp[color[i]] - d);
	mp[color[i]] = d;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	edge.resize(n);

	for (int i = 0; i < n; ++i) cin >> color[i];

	int a, b;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	map<int, int> mp;
	dfs(0, -1, 0, mp);
	cout << ans;
}