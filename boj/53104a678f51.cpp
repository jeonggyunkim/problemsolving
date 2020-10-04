#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> ans;
vector<vector<int>> adj;

void dfs(int now) {
	for (int i = 0; i < n;) {
		if (adj[now][i] > 0) {
			adj[now][i]--;
			adj[i][now]--;
			dfs(i);
		}
		else ++i;
	}
	ans.push_back(now);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	adj.resize(n, vector<int>(n));

	int t;
	for (int i = 0; i < n; ++i) {
		t = 0;
		for (int j = 0; j < n; ++j) {
			cin >> adj[i][j];
			t += adj[i][j];
		}
		if (t & 1) {
			cout << -1;
			return 0;
		}
	}

	dfs(0);

	for (int i = ans.size() - 1; i >= 0; --i) {
		cout << ans[i] + 1 << ' ';
	}
}