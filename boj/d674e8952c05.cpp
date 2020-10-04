#include <iostream>
#define INF ((1 << 29) - 1)
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int dist[101][101] = {};
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
		if (i != j) dist[i][j] = INF;
	}

	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dist[i][j] == INF) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}