#include <bits/stdc++.h>
using namespace std;

vector<int> p, route, s;
vector<vector<int>> des;

int dfs(int i) {
	s[i] = 1;
	route.push_back(i);
	for (int u : des[i]) {
		s[i] += dfs(u);
	}
	return s[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	p.resize(n + 1);
	s.resize(n + 1, 0);
	des.resize(n + 1);
	for (int i = 2; i <= n; ++i) {
		cin >> p[i];
		des[p[i]].push_back(i);
	}

	dfs(1);

	vector<int> index(n + 1);
	for (int i = 0; i < n; ++i) index[route[i]] = i;

	int a, b;
	while (q--) {
		cin >> a >> b;
		if (b > s[a]) cout << -1 << '\n';
		else {
			cout << route[index[a] + b - 1] << '\n';
		}
	}
}