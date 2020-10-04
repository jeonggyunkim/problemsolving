#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ii> edge(m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[i] = {a, b};
	}

	vector<vector<bool>> pos(n, vector<bool>(n, 0));

	for (int rep = 0; rep < 2; ++rep) {
		vector<vector<int>> dist(n, vector<int>(n, INF));

		for (int i = 0; i < n; ++i) dist[i][i] = 0;

		if (rep) {
			for (ii e: edge) dist[e.first][e.second] = 1;
		}
		else {
			for (ii e: edge) dist[e.second][e.first] = 1;
		}

		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][j] != INF) pos[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (pos[i][j]) cnt++;
		}
		cout << n - cnt << '\n';
	}
}
