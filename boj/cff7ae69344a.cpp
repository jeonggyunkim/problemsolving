#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define INF 987654321

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> dist(n, vector<int>(n, INF));
	for (int i = 0; i < n; ++i) dist[i][i] = 0;

	int a, b, w;
	vector<tuple<int, int, int>> edge;
	while (m--) {
		cin >> a >> b >> w;
		a--; b--;
		dist[a][b] = min(dist[a][b], w);
		dist[b][a] = min(dist[b][a], w);
		edge.push_back({a, b, w});
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < n; ++i) {
		int time = -1;
		for (tuple<int, int, int> u: edge) {
			int first = min(dist[i][get<0>(u)], dist[i][get<1>(u)]);
			int second = max(dist[i][get<0>(u)], dist[i][get<1>(u)]);
			if (second >= first + get<2>(u)) {
				time = max(time, 2 * (first + get<2>(u)));
			}
			else {
				time = max(time, first + second + get<2>(u));
			}
		}
		ans = min(ans, time);
	}
	cout << ans / 2;
	if (ans & 1) cout << ".5\n";
	else cout << ".0\n";
}