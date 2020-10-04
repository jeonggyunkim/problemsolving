#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

typedef struct {
	int s;
	int d;
	int w;
} ed;

int bellman(vector<ed>& edge, vector<vector<bool>>& cango, int v, int w) {
	vector<int> dist(v, INF);

	dist[0] = 0;

	for (int i = 0; i < v; ++i) {
		bool upd = 0;
		for (int j = 0; j < w; ++j) {
			if (dist[edge[j].s] == INF) continue;
			int t = dist[edge[j].s] + edge[j].w;
			if (dist[edge[j].d] > t) {
				dist[edge[j].d] = t;
				upd = 1;
			}
		}
		if (!upd) break;
	}

	for (int i = 0; i < w; ++i) {
		if (dist[edge[i].s] != INF && dist[edge[i].d] > dist[edge[i].s] + edge[i].w) {
			return -INF;
		}
	}

	return dist[1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int v, w;
		cin >> v >> w;

		vector<ed> edge(w);
		vector<vector<bool>> cango(v, vector<bool>(v, 0));

		for (int i = 0; i < w; ++i) {
			cin >> edge[i].s >> edge[i].d >> edge[i].w;
			cango[edge[i].s][edge[i].d] = 1;
		}

		for (int k = 0; k < v; ++k) for (int i = 0; i < v; ++i) for (int j = 0; j < v; ++j) {
			if (cango[i][k] & cango[k][j]) cango[i][j] = 1;
		}

		if (cango[0][1] == 0) {
			cout << "UNREACHABLE\n";
			continue;
		}

		int mindist = bellman(edge, cango, v, w);
		if (mindist == -INF) cout << "INFINITY" << ' ';
		else cout << mindist << ' ';

		for (int i = 0; i < w; ++i) edge[i].w = -edge[i].w;

		int maxdist = bellman(edge, cango, v, w);
		if (maxdist == -INF) cout << "INFINITY";
		else cout << -maxdist;

		cout << '\n';
	}
}
