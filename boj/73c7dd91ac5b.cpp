#include <iostream>
#include <queue>
#include <tuple>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> i4;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int hum[500][500];
int map[500][500];
int land[9];
i4 unit[62500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, h, w;
	cin >> n >> h >> w;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> hum[i][j];
			hum[i][j]--;
		}
	}

	for (int i = 0; i < n; ++i) cin >> land[i];

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			hum[i][j] = land[hum[i][j]];
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		unit[i] = {a, b, c, d};
		map[c][d] = i + 1;
	}

	int k;
	cin >> k;

	vector<vector<int>> dist(h, vector<int>(w, INF));
	while (k--) {
		int u, a, b;
		cin >> u >> a >> b;
		u--;

		if (map[a][b]) continue;

		vector<ii> changed;

		priority_queue<iii, vector<iii>, greater<iii>> pq;
		dist[get<2>(unit[u])][get<3>(unit[u])] = 0;
		changed.push_back({get<2>(unit[u]), get<3>(unit[u])});
		pq.push({0, get<2>(unit[u]), get<3>(unit[u])});
		int maxd = get<0>(unit[u]);
		while (!pq.empty()) {
			iii now = pq.top(); pq.pop();
			int d = get<0>(now), x = get<1>(now), y = get<2>(now);
			if (d > dist[x][y]) continue;
			for (int k = 0; k < 4; ++k) {
				int i = x + loc[k][0];
				int j = y + loc[k][1];
				if (i < 0 || i >= h || j < 0 || j >= w || hum[i][j] == -1) continue;
				if (map[i][j] && get<1>(unit[map[i][j] - 1]) != get<1>(unit[u])) continue;

				bool imp = 0;
				for (int l = 0; l < 4; ++l) {
					int a = i + loc[l][0];
					int b = j + loc[l][1];
					if (a < 0 || a >= h || b < 0 || b >= w) continue;

					if (map[a][b] && get<1>(unit[map[a][b] - 1]) != get<1>(unit[u])) imp = 1;
				}
				if (i == a && j == b) imp = 0;
				if (imp) continue;

				int nowd = d + hum[i][j];
				if (nowd > maxd) continue;
				if (nowd < dist[i][j]) {
					dist[i][j] = nowd;
					changed.push_back({i, j});
					pq.push({nowd, i, j});
				}
			}
		}
		if (dist[a][b] != INF) {
			i4 unit_before = unit[u];
			map[get<2>(unit_before)][get<3>(unit_before)] = 0;
			map[a][b] = u + 1;
			unit[u] = {get<0>(unit_before), get<1>(unit_before), a, b};
		}

		for (ii u: changed) {
			dist[u.first][u.second] = INF;
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << get<2>(unit[i]) << ' ' << get<3>(unit[i]) << '\n';
	}
}