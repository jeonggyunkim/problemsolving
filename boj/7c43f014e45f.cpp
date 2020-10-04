#include <iostream>
#include <vector>
using namespace std;

int h[500];
vector<vector<int>> edge;
int mind[500][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	edge.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		mind[i][0] = h[i];
	}

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for (int move = 1; move <= 500; ++move) {
		for (int i = 0; i < n; ++i) {
			int now = 54321;
			for (int u: edge[i]) {
				if (mind[u][move - 1] != -1) {
					now = min(now, mind[u][move - 1]);
				}
			}
			if (now == 54321) mind[i][move] = -1;
			else mind[i][move] = now;
		}
	}

	int q;
	cin >> q;
	while (q--) {
		cin >> a >> b;
		a--;
		cout << mind[a][b] << '\n';
	}
}