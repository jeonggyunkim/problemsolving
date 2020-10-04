#include <iostream>
#include <vector>
#include <queue>
#define INF ((1 << 29) - 1)
using namespace std;

typedef pair<int, int> ii;
vector<ii> edge[801];

void da(vector<int>& dist, int s) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, s));
	dist[s] = 0;
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		int d = now.first, u = now.second;
		if (d > dist[u]) continue;
		for (ii v: edge[u]) {
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, e;
	cin >> n >> e;
	
	int a, b, c;
	while (e--) {
		cin >> a >> b >> c;
		edge[a].push_back(ii(b, c));
		edge[b].push_back(ii(a, c));
	}
	
	vector<int> dist1(n + 1, INF);
	vector<int> dist2(n + 1, INF);
	vector<int> dist3(n + 1, INF);
	cin >> a >> b;
	
	da(dist1, 1);
	da(dist2, a);
	da(dist3, b);
	
	int ans = min(dist1[a] + dist2[b] + dist3[n], dist1[b] + dist3[a] + dist2[n]);
	if (ans >= INF) cout << -1;
	else cout << ans;
}