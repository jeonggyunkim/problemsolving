#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> child;
int sum[100010];

void dfs(int i) {
	for (int u: child[i]) {
		sum[u] += sum[i];
		dfs(u);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q, t;
	cin >> n >> q;
	child.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t != -1) {
			t--;
			child[t].push_back(i);
		}
	}

	int a, b;
	while (q--) {
		cin >> a >> b;
		a--;
		sum[a] += b;
	}
	dfs(0);

	for (int i = 0; i < n; ++i) {
		cout << sum[i] << ' ';
	}
}