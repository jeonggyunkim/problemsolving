#include <iostream>
#include <vector>
#include <queue>
#define D 50000
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> dist(100001, INF);

	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for (int i = 0; (1 << i) < 50000; ++i) {
		dist[(1 << i) + D] = i + 1;
		dist[-(1 << i) + D] = i + 1;
		pq.push({i + 1, (1 << i)});
		pq.push({i + 1, -(1 << i)});
	}
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		for (int i = 0; (1 << i) < 50000; ++i) {
			int x = now.second + (1 << i);
			int d = now.first + i + 5;
			if (x >= -50000 && x <= 50000) {
				if (dist[x + D] > d) {
					dist[x + D] = d;
					pq.push({d, x});
				}
			}
			x = now.second - (1 << i);
			if (x >= -50000 && x <= 50000) {
				if (dist[x + D] > d) {
					dist[x + D] = d;
					pq.push({d, x});
				}
			}
		}
	}

	int tc, t;
	cin >> tc;
	while (tc--) {
		cin >> t;
		cout << dist[t + D] << '\n';
	}
}