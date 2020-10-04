#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[32001];
vector<int> s;
int visited[32001];

void dfs(int n) {
	visited[n] = 1;
	for (int i: edge[n]) {
		if (!visited[i]) dfs(i);
	}
	s.push_back(n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		edge[a].push_back(b);
	}

	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) dfs(i);
	}

	for (int i = s.size() - 1; i >= 0; --i) cout << s[i] << ' ';
}