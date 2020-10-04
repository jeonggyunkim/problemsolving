#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int d[10][1 << 10];
	for (int i = 0; i < n; ++i) for (int j = 0; j < (1 << n) - 1; ++j) d[i][j] = 987654321;

	int dist[10][10];
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> dist[i][j];

	queue<ii> q;
	d[k][((1 << n) - 1) ^ (1 << k)] = 0;
	q.push(ii(k, ((1 << n) - 1) ^ (1 << k)));
	while (!q.empty()) {
		ii u = q.front();
		q.pop();
		int now = u.first;
		int mask = u.second;
		for (int i = 0; i < n; ++i) {
			int next = mask & ~(1 << i);
			if (dist[now][i] + d[now][mask] < d[i][next]) {
				d[i][next] = dist[now][i] + d[now][mask];
				q.push(ii(i, next));
			}
		}
	}

	int ans = 987654321;
	for (int i = 0; i < n; ++i) ans = min(ans, d[i][0]);
	cout << ans;
}