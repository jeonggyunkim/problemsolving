#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> edge;
vector<int> visited, sccId;
stack<int> s;
int vCounter, sCounter;

int dfs(int n) {
	int ret = visited[n] = vCounter++;
	s.push(n);

	for (int u: edge[n]) {
		if (visited[u] == -1) {
			int r = dfs(u);
			ret = min(ret, r);
		}
		else if (visited[u] < visited[n] && sccId[u] == -1) ret = min(ret, visited[u]);
	}

	if (ret == visited[n]) {
		while (true) {
			int t = s.top(); s.pop();
			sccId[t] = sCounter;
			if (t == n) break;
		}
		sCounter++;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;

	edge.resize(v);
	sccId.resize(v, -1);
	visited.resize(v, -1);

	int a, b;
	while (e--) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
	}

	for (int i = 0; i < v; ++i) {
		if (visited[i] == -1) dfs(i);
	}

	vector<vector<int>> ans(sCounter);
	vector<int> index(sCounter);
	int indcount = 0;
	for (int i = 0; i < v; ++i) {
		if (ans[sccId[i]].size() == 0) index[indcount++] = sccId[i];
		ans[sccId[i]].push_back(i);
	}

	cout << sCounter << '\n';
	for (int i = 0; i < sCounter; ++i) {
		int j = index[i];
		sort(ans[j].begin(), ans[j].end());
		for (int u: ans[j]) cout << u + 1 << ' ';
		cout << "-1\n";
	}
}