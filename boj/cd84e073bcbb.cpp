#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int cnt;
int v[1000000];
int bm[1000010];
vector<vector<int>> edge;

bool dfs(int i) {
	if (v[i] == cnt) return 0;
	v[i] = cnt;

	for (int u: edge[i]) {
		if (bm[u] == -1 || dfs(bm[u])) {
			bm[u] = i;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a, b;
	edge.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		edge[i].push_back(a);
		if (a != b) edge[i].push_back(b);
	}

	memset(bm, -1, sizeof(bm));
	for (int i = 0; i < n; ++i) {
		cnt++;
		if (!dfs(i)) {
			cout << -1;
			return 0;
		}
	}

	vector<int> ans(n);
	for (int i = 0; i <= 1000000; ++i) {
		if (bm[i] != -1) ans[bm[i]] = i;
	}

	for (int u: ans) cout << u << '\n';
}