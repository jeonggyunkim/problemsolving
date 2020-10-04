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
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
		if (dist[i][j] > dist[i][k] + dist[k][j]) {
			dist[i][j] = dist[i][k] + dist[k][j];
		}
	}

	int ans, ansmin = INF;
	for (int i = 1; i <= n; ++i) {
		int t = 0;
		for (int j = 1; j <= n; ++j) t += dist[i][j];
		if (t < ansmin) {
			ansmin = t;
			ans = i;
		}
	}

	cout << ans;
}