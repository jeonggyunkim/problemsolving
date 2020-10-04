#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

vector<ii> edge[10001];
int time[10001];
vector<int> lastv[10001];
bool visit[10001];
vector<int> topo;

void dfs(int i) {
	visit[i] = 1;
	for (ii u: edge[i]) {
		if (!visit[u.first]) dfs(u.first);
	}
	topo.push_back(i);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b, d;
	while (m--) {
		cin >> a >> b >> d;
		edge[a].push_back(ii(b, d));
	}

	int s, f;
	cin >> s >> f;

	dfs(s);

	for (int j = topo.size() - 1; j >= 0; --j) {
		int i = topo[j];
		for (ii u: edge[i]) {
			if (time[u.first] < time[i] + u.second) {
				time[u.first] = time[i] + u.second;
				lastv[u.first].clear();
				lastv[u.first].push_back(i);
			}
			else if (time[u.first] == time[i] + u.second) {
				lastv[u.first].push_back(i);
			}
		}
	}

	int ans = 0;
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	q.push(f);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		ans += lastv[now].size();
		for (int u: lastv[now]) {
			if (u != s && visit[u] == 0) {
				q.push(u);
				visit[u] = 1;
			}
		}
	}

	cout << time[f] << '\n' << ans;
}