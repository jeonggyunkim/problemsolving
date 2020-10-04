#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int item[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<int>> dist(n, vector<int>(n, INF));

	for (int i = 0; i < n; ++i) cin >> item[i];

	for (int i = 0; i < n; ++i) dist[i][i] = 0;

	int a, b, w;
	while (r--) {
		cin >> a >> b >> w;
		a--; b--;
		dist[a][b] = w;
		dist[b][a] = w;
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < n; ++i) {
		int now = 0;
		for (int j = 0; j < n; ++j) {
			if (dist[i][j] <= m) {
				now += item[j];
			}
		}
		ans = max(ans, now);
	}

	cout << ans;
}