#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b, c;
	cin >> n >> m >> a >> b >> c;

	vector<vector<int>> edge(n);
	for (int i = 0; i < m; ++i) {
		int p, q;
		cin >> p >> q;
		p--; q--;
		edge[p].push_back(q);
	}

	set<int> reach[50][101];

	for (int i = 0; i < n; ++i) {
		reach[i][0].insert(i);
	}

	for (int d = 1; d <= 100; ++d) {
		for (int i = 0; i < n; ++i) {
			for (int u: edge[i]) {
				for (int v: reach[u][d - 1]) {
					reach[i][d].insert(v);
				}
			}
		}
	}

	int win[100] = {};
	win[n - 1] = 1;
	int target = 1;
	while (1) {
		bool change = 0;
		bool target_get = 0;
		for (int i = 0; i < n; ++i) {
			if (win[i]) continue;
			int cnt = 0;
			int arr[3] = {};
			for (int mv: {a, b, c}) {
				int mi = 999;
				for (int u: reach[i][mv]) {
					if (win[u]) {
						mi = min(mi, win[u] + 1);
					}
				}
				if (mi != 999) {
					cnt++;
					if (mv == a) arr[0] = mi;
					if (mv == b) arr[1] = mi;
					if (mv == c) arr[2] = mi;
				}
			}

			if (cnt == 3) {
				int dist = max({arr[0], arr[1], arr[2]});
				if (dist == target) {
					win[i] = dist;
					target_get = 1;
				}
				change = 1;
			}
		}
		if (!change) break;
		if (!target_get) {
			target++;
		}
	}
	if (!win[0]) cout << "IMPOSSIBLE";
	else cout << win[0] - 1;
}