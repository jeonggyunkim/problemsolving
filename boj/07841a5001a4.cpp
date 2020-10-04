#include <iostream>
#include <vector>
#include <queue>
#define INF ((1 << 30) - 1)
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, m, s, f;
	cin >> v >> m;
	vector<vector<ii>> edge(v + 1);

	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		edge[a].push_back(ii(b, c));
	}
	cin >> s >> f;

	vector<int> dist(v + 1, INF);
	vector<int> last(v + 1);
	dist[s] = 0;

	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, s));
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		int d = now.first, u = now.second;
		if (d > dist[u]) continue;
		for (ii v: edge[u]) {
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				last[v.first] = u;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}

	vector<int> re;
	int now = f;
	while (now != s) {
		re.push_back(now);
		now = last[now];
	}

	cout << dist[f] << '\n';
	cout << re.size() + 1 << '\n';
	cout << s << ' ';
	for (int i = re.size() - 1; i >= 0; --i) cout << re[i] << ' ';
}