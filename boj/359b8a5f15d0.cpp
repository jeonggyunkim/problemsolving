#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

vector<int> p;
vector<int> vis;
vector<vector<int>> edge;

int find(int n) {
	if (n == p[n]) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) p[b] = a;
}

void dfs(int n, int np) {
	vis[n] = 1;
	for (int u: edge[n]) {
		if (u != np) {
			if (vis[p[u]] == 1) {
				cout << "inconsistent";
				exit(0);
			}
			else if (vis[p[u]] == -1) {
				dfs(p[u], n);
			}
		}
	}
	vis[n] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	p.resize(n);
	for (int i = 0; i < n; ++i) {
		p[i] = i;
	}

	vector<ii> arr;
	int a, b;
	char c;
	while (m--) {
		cin >> a >> c >> b;
		if (c == '=') merge(a, b);
		else if (c == '>')	arr.push_back(ii(a, b));
		else arr.push_back(ii(b, a));
	}

	edge.resize(n);
	for (ii u: arr) {
		edge[p[u.first]].push_back(p[u.second]);
	}

	vis.resize(n, -1);
	for (int i = 0; i < n; ++i) {
		if (vis[p[i]] == -1) {
			dfs(p[i], -1);
		}
	}
	cout << "consistent";
}