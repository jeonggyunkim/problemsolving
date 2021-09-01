#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> ii;

int parent[100010];
int color[100010];

int p[100010];
map<int, int> mp[100010];

int find(int i) {
	if (i == p[i]) return i;
	return p[i] = find(p[i]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 2; i <= n; ++i) cin >> parent[i];
	for (int i = 1; i <= n; ++i) cin >> color[i];

	vector<ii> query(n + q - 1);
	for (ii& u: query) {
		cin >> u.first >> u.second;
	}

	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		mp[i][color[i]] = 1;
	}

	vector<int> ans(q);
	int cnt = 0;
	for (int i = query.size() - 1; i >= 0; --i) {
		if (query[i].first == 1) {
			int a = find(query[i].second);
			int b = find(parent[query[i].second]);
			if (mp[a].size() < mp[b].size()) {
				for (auto u: mp[a]) mp[b][u.first] += u.second;
				mp[a].clear();
				p[a] = b;
			}
			else {
				for (auto u: mp[b]) mp[a][u.first] += u.second;
				mp[b].clear();
				p[b] = a;
			}
		}
		else {
			ans[cnt++] = mp[find(query[i].second)].size();
		}
	}

	for (int i = q - 1; i >= 0; --i) cout << ans[i] << '\n';
}