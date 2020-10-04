#include <iostream>
#include <vector>
#define sq(n) ((n) * (n))
using namespace std;

vector<bool> vis;
vector<vector<int>> edge;

void dfs(int i) {
	vis[i] = 1;
	for (int u: edge[i]) {
		if (!vis[u]) dfs(u);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		vector<int> x(n), y(n), r(n);
		for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> r[i];

		edge = vector<vector<int>>(n);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (sq(x[i] - x[j]) + sq(y[i] - y[j]) <= sq(r[i] + r[j])) {
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}

		vis = vector<bool>(n, 0);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				dfs(i);
				ans++;
			}
		}

		cout << ans << '\n';
	}
}