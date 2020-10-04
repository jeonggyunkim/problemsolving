#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#define N 100010
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

ii index[N];
int cnt = 1;
iii to_sort[N];
int sz;
int tree[2 * N];
vector<vector<int>> child;
int ans[N];

void insert(int i, int d) {
	while (i <= sz) {
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

void dfs(int i, int d) {
	get<1>(to_sort[i]) = N - d;
	index[i].first = cnt++;
	for (int u: child[i]) {
		dfs(u, d + 1);
	}
	index[i].second = cnt++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	child.resize(n);
	sz = 2 * n;

	for (int i = 0; i < n; ++i) {
		cin >> get<0>(to_sort[i]);
		get<2>(to_sort[i]) = i;
	}

	int t;
	for (int i = 1; i < n; ++i) {
		cin >> t;
		t--;
		child[t].push_back(i);
	}

	dfs(0, 0);
	sort(to_sort, to_sort + n);

	for (int i = n - 1; i >= 0; --i) {
		int ind = get<2>(to_sort[i]);
		ans[ind] = get(index[ind].second) - get(index[ind].first - 1);
		insert(index[ind].second, 1);
	}

	for (int i = 0; i < n; ++i) cout << ans[i] << '\n';
}