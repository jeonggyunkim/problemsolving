#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> ii;

int dd(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;

		vector<int> x(n), y(n);
		for (int i = 0; i < n; ++i) cin >> x[i];
		for (int i = 0; i < n; ++i) cin >> y[i];

		vector<vector<int>> dist(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int r = dd(x[i], y[i], x[j], y[j]);
				dist[i][j] = dist[j][i] = r;
			}
		}

		int a, b;
		while (m--) {
			cin >> a >> b;
			dist[a][b] = dist[b][a] = 0;
		}

		vector<bool> add(n, 0);
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.push(ii(0, 0));

		double ans = 0;
		while (!pq.empty()) {
			ii now = pq.top(); pq.pop();
			int d = now.first, u = now.second;
			if (add[u]) continue;
			ans += sqrt(d);
			add[u] = 1;
			for (int i = 0; i < n; ++i) {
				if (!add[i]) pq.push(ii(dist[u][i], i));
			}
		}
		cout.precision(15);
		cout << ans << '\n';
	}
}
