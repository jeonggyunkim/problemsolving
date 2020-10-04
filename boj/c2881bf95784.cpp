#include <iostream>
#include <vector>
using namespace std;

int n, t;
vector<int> edge[501];
int time[501];
int maxtime[501];
vector<int> topo;

void dfs(int i) {
	maxtime[i] = time[i];
	for (int u: edge[i]) {
		if (maxtime[u] == 0) dfs(u);
	}
	topo.push_back(i);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> time[i];
		while (cin >> t, t != -1) {
			edge[t].push_back(i);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (maxtime[i] == 0) dfs(i);
	}

	for (int j = n - 1; j >= 0; --j) {
		int i = topo[j];
		for (int u: edge[i]) {
			maxtime[u] = max(maxtime[u], maxtime[i] + time[u]);
		}
	}

	for (int i = 1; i <= n; ++i) cout << maxtime[i] << ' ';
}