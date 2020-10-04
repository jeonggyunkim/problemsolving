#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int n;
vector<vector<ii>> edge;
vector<int> child_count;
vector<int> depth;
vector<long long> ans;

int dfs(int i, int p, int d) {
	child_count[i] = 1;
	depth[i] = d;
	for (ii u: edge[i]) {
		if (u.first != p) {
			child_count[i] += dfs(u.first, i, d + u.second);
		}
	}
	return child_count[i];
}

void dfs_ans(int i, int p, long long p_sum) {
	p_sum += (depth[i] - depth[p]) * (n - 2 * child_count[i]);
	ans[i] = p_sum;
	for (ii u: edge[i]) {
		if (u.first != p) {
			dfs_ans(u.first, i, p_sum);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	edge.resize(n);

	int a, b, c;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b >> c;
		a--; b--;
		edge[a].push_back(ii(b, c));
		edge[b].push_back(ii(a, c));
	}

	child_count.resize(n);
	depth.resize(n);

	depth[0] = 0;
	dfs(0, -1, 0);

	ans.resize(n, 0);
	for (int i = 0; i < n; ++i) ans[0] += depth[i];

	for (ii u: edge[0]) {
		dfs_ans(u.first, 0, ans[0]);
	}

	for (long long u: ans) cout << u << '\n';
}