#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

typedef pair<int, int> ii;

vector<ii> sub;
vector<vector<int>> edge;
vector<int> tree;
int counter = 0, n;

void set(int i) {
	while (i <= n) {
		tree[i]++;
		i += (i & -i);
	}
}

int get(int i) {
	int ret = 0;
	while (i) {
		ret += tree[i];
		i &= i - 1;
	}
	return ret;
}

void dfs(int i) {
	sub[i].first = ++counter;
	for (int u : edge[i]) {
		if (sub[u].first == -1) dfs(u);
	}
	sub[i].second = counter;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, c;
	cin >> n >> m >> c;

	sub.resize(n + 1, ii(-1, -1));
	edge.resize(n + 1);
	tree.resize(n + 1, 0);

	vector<ii> color(n);
	for (int i = 0; i < n; ++i) {
		cin >> color[i].first;
		color[i].second = i + 1;
	}

	sort(color.begin(), color.end());

	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(1);

	vector<ii> q(m);
	for (int i = 0; i < m; ++i) cin >> q[i].second >> q[i].first;
	sort(q.begin(), q.end());

	int sum = 0;
	int i = 0, j = 0;
	for (int col = 1; col <= c; ++col) {
		while (i < n && color[i].first == col) {
			set(sub[color[i].second].first);
			i++;
		}
		while (j < m && q[j].first == col) {
			int t = get(sub[q[j].second].second) - get(sub[q[j].second].first - 1);
			sum += t;
			sum %= MOD;
			j++;
		}
	}

	cout << sum;
}