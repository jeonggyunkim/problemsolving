#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int n = 200000, tree[200001];

void set(int i, int d) {
	while (i <= n) {
		tree[i] += d;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(tree, 0, sizeof(tree));

		int n, m, t;
		cin >> n >> m;
		vector<int> index(100001);
		for (int i = 1; i <= n; ++i) {
			index[i] = n - i + 1;
			set(i, 1);
		}

		int ind = n + 1;
		while (m--) {
			cin >> t;
			cout << n - get(index[t]) << ' ';
			set(index[t], -1);
			index[t] = ind++;
			set(index[t], 1);
		}
		cout << '\n';
	}
}