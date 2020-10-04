#include <iostream>
#define INF ((1 << 29) - 1)
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int dist[101][101] = {};
	int pre[101][101] = {};
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
		if (i != j) dist[i][j] = INF;
	}

	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		pre[a][b] = a;
	}

	for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
		if (dist[i][j] > dist[i][k] + dist[k][j]) {
			dist[i][j] = dist[i][k] + dist[k][j];
			pre[i][j] = pre[k][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dist[i][j] == INF) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	int way[101];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dist[i][j] == INF || dist[i][j] == 0) cout << 0 << '\n';
			else {
				int now = j;
				int k = 0;
				while (now != i) {
					way[k++] = now;
					now = pre[i][now];
				}
				cout << k + 1 << ' ';
				cout << i << ' ';
				for (int ii = k - 1; ii >= 0; --ii) cout << way[ii] << ' ';
				cout << '\n';
			}
		}
	}
}