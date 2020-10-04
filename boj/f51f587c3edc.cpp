#include <iostream>
#include <vector>
#include <queue>
#define INF (1 << 30)
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);

	vector<ii> edge[2][10010];

	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		edge[0][a].push_back(ii(b, c));
		edge[1][b].push_back(ii(a, c));
	}

	int dist[2][10010];
	for (int i = 0; i < 2; ++i) for (int j = 0; j < 10010; ++j) dist[i][j] = INF;

	for (int rep = 0; rep < 2; ++rep) {
		dist[rep][x] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, x));
		while (!pq.empty()) {
			ii t = pq.top(); pq.pop();
			int d = t.first, u = t.second;
			if (d > dist[rep][u]) continue;
			for (int i = 0; i < edge[rep][u].size(); ++i) {
				ii v = edge[rep][u][i];
				if (dist[rep][u] + v.second < dist[rep][v.first]) {
					dist[rep][v.first] = dist[rep][u] + v.second;
					pq.push(ii(dist[rep][v.first], v.first));
				}
			}
		}
	}

	int max = -1;
	for (int i = 1; i <= n; ++i) {
		if (i != x && dist[0][i] + dist[1][i] > max) max = dist[0][i] + dist[1][i];
	}
	printf("%d\n", max);
}

