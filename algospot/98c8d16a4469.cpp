#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int v, m, n;
		cin >> v >> m >> n;

		vector<vector<int>> dist(v, vector<int>(v, INF));
		int a, b, c;
		while (m--) {
			cin >> a >> b >> c;
			if (c < dist[a][b]) {
				dist[a][b] = dist[b][a] = c;
			}
		}

		for (int i = 0; i < v; ++i) dist[i][i] = 0;

		for (int k = 0; k < v; ++k) for (int i = 0; i < v; ++i) for (int j = 0; j < v; ++j) {
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}

		int ans = 0;
		while (n--) {
			cin >> a >> b >> c;
			if (c >= dist[a][b]) ans++;
			else {
				for (int i = 0; i < v; ++i) for (int j = 0; j < v; ++j) {
					dist[i][j] = min(dist[i][j], min(dist[i][a] + c + dist[b][j], dist[i][b] + c + dist[a][j]));
				}
			}
		}

		cout << ans << '\n';
	}
}
