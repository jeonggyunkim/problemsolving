#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> v;
vector<vector<int>> edge;
vector<int> bm;

bool dfs(int i) {
	if (v[i]) return 0;
	v[i] = 1;

	for (int u: edge[i]) {
		if (bm[u] == -1 || dfs(bm[u])) {
			bm[u] = i;
			return 1;
		}
	}
	return 0;
}

bool isPrime(int n) {
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;
	vector<int> first, second;

	cin >> t;
	first.push_back(t);
	for (int i = 1; i < n; ++i) {
		cin >> t;
		if ((t ^ first[0]) & 1) second.push_back(t);
		else first.push_back(t);
	}

	if (first.size() != second.size()) {
		cout << -1;
		return 0;
	}

	n = first.size();

	edge.resize(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (isPrime(first[i] + second[j])) edge[i].push_back(j);
		}
	}

	vector<int> ans;
	for (int u: edge[0]) {
		int size = 1;
		bm = vector<int> (n, -1);
		bm[u] = 0;
		for (int i = 1; i < n; ++i) {
			v = vector<bool>(n, 0);
			v[0] = 1;
			if (dfs(i)) size++;
		}
		if (size == n) ans.push_back(second[u]);
	}

	sort(ans.begin(), ans.end());
	if (ans.size() == 0) cout << -1;
	else for (int u: ans) cout << u << ' ';
}