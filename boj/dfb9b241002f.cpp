#include <iostream>
#include <vector>
#define INF ((1 << 30) - 1)
using namespace std;

struct ed{
	int s;
	int d;
	int w;
	ed(int s, int d, int w) : s(s), d(d), w(w) { }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int v, m, w;
		cin >> v >> m >> w;
		vector<ed> edge;

		int a, b, d;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> d;
			edge.push_back(ed(a, b, d));
			edge.push_back(ed(b, a, d));
		}
		for (int i = 0; i < w; ++i) {
			cin >> a >> b >> d;
			edge.push_back(ed(a, b, -d));
		}

		int e = 2 * m + w;
		vector<int> dist(v + 1, INF);
		dist[1] = 0;

		for (int i = 0; i < v; ++i) {
			for (int j = 0; j < e; ++j) {
				int t = dist[edge[j].s] + edge[j].w;
				if (dist[edge[j].d] > t) dist[edge[j].d] = t;
			}
		}

		bool brk = false;
		for (int i = 0; i < e; ++i) {
			if (dist[edge[i].s] != INF && dist[edge[i].d] > dist[edge[i].s] + edge[i].w) {
				cout << "YES\n";
				brk = true;
				break;
			}
		}
		if (!brk) cout << "NO\n";
	}
}