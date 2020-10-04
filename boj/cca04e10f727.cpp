#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> edge;
bool visDfs[1000], visBfs[1000];

void dfs(int n) {
	cout << n + 1 << ' ';
	visDfs[n] = 1;
	for (int u: edge[n]) {
		if (!visDfs[u]) dfs(u);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int v;
	cin >> v;
	v--;

	int a, b;
	edge.resize(n);
	while (m--) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		sort(edge[i].begin(), edge[i].end());
	}

	dfs(v);
	cout << '\n';

	queue<int> q;
	q.push(v);
	visBfs[v] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		cout << now + 1 << ' ';
		for (int u: edge[now]) {
			if (!visBfs[u]) {
				q.push(u);
				visBfs[u] = 1;
			}
		}
	}
}