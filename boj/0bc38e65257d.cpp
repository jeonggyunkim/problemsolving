#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int a[30][2];
int dist[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dist, -1, sizeof(dist));

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n + m; ++i) {
		cin >> a[i][0] >> a[i][1];
	}

	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 1; i <= 6; ++i) {
			int next = now + i;
			for (int j = 0; j < n + m; ++j) {
				if (a[j][0] == next) next = a[j][1];
			}
			if (next <= 100 && dist[next] == -1) {
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}
	cout << dist[100];
}