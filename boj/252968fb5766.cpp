#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

vector<vector<ii>> edge;
vector<int> list;
bool vis[100000];
int p[100000];

void dfs(int i) {
	list.push_back(i);
	vis[i] = 1;
	for (ii u: edge[i]) {
		if (!vis[u.first]) {
			dfs(u.first);
		}
	}
}

int find(int i) {
	if (i == p[i]) return i;
	else return p[i] = find(p[i]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	p[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	edge.resize(n);
	for (int i = 0; i < n; ++i) p[i] = i;

	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		a--; b--;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}

	long long ans = 0;
	int maxw = -1;
	int dfscnt = 0;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(i);
			dfscnt++;
			vector<iii> edge_list;

			for (int u: list) {
				for (ii v: edge[u]) {
					edge_list.push_back({v.second, u, v.first});
				}
			}

			sort(edge_list.begin(), edge_list.end());
			for (iii u: edge_list) {
				int a = get<1>(u), b = get<2>(u);
				if (find(a) != find(b)) {
					ans += get<0>(u);
					maxw = max(maxw, get<0>(u));
					merge(a, b);
				}
			}
			list.clear();
		}
	}
	
	if (dfscnt == 1) cout << ans - maxw;
	else if (dfscnt == 2) cout << ans;
	else return -1;
}