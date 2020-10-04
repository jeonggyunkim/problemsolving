#include <iostream>
#include <vector>
#include <tuple>
#define INF 987654321
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> edge(m);
	
	int a, b, w;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> w;
		edge[i] = {a, b, w};
	}

	vector<long long> dist(n + 1, INF);
	dist[1] = 0;
	
	for (int i = 1; i <= n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			tie(a, b, w) = edge[j];
			if (dist[a] == INF) continue;
			int t = dist[a] + w;
			if (dist[b] > t) dist[b] = t;
		}
	}
	
	for (int i = 0; i < m; ++i) {
		tie(a, b, w) = edge[i];
		if (dist[a] != INF && dist[b] > dist[a] + w) {
			cout << -1;
			return 0;
		}
	}
	
	for (int i = 2; i <= n; ++i) {
		if (dist[i] == INF) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}
}