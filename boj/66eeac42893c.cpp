#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int n;
vector<vector<int>> child;
vector<int> tree;
vector<ii> index;

void insert(int i, int d) {
	while (i <= n) {
		tree[i] += d;
		i += (i & -i);
	}
}

int get(int i) {
	int ret = 0;
	while (i) {
		ret += tree[i];
		i &= (i - 1);
	}
	return ret;
}

int cnt;

void dfs(int i) {
	index[i].first = ++cnt;
	for (int u: child[i]) {
		dfs(u);
	}
	index[i].second = cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q, t;
	cin >> n >> q;
	child.resize(n + 1);
	tree.resize(n + 1);
	index.resize(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> t;
		if (t != -1) {
			child[t].push_back(i);
		}
	}
	dfs(1);

	int op, a, b;
	while (q--) {
		cin >> op >> a;
		if (op == 1) {
			cin >> b;
			insert(index[a].first, b);
		}
		else {
			cout << get(index[a].second) - get(index[a].first - 1) << '\n';
		}
	}
}