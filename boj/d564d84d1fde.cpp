#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> edge;
vector<int> visited, sccId;
stack<int> st;
int vCounter, sCounter;

int dfs(int n) {
	int ret = visited[n] = vCounter++;
	st.push(n);

	for (int u: edge[n]) {
		if (visited[u] == -1) {
			int r = dfs(u);
			ret = min(ret, r);
		}
		else if (visited[u] < visited[n] && sccId[u] == -1) ret = min(ret, visited[u]);
	}

	if (ret == visited[n]) {
		while (true) {
			int t = st.top(); st.pop();
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

	int n, m;
	cin >> n >> m;

	edge.resize(n);
	sccId.resize(n, -1);
	visited.resize(n, -1);

	int a, b;
	while (m--) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
	}

	vector<int> atm(n);
	for (int i = 0; i < n; ++i) cin >> atm[i];

	int s, p;
	cin >> s >> p;
	s--;

	dfs(s);

	vector<int> price_scc(sCounter, 0), value(sCounter, 0);
	vector<vector<int>> child_scc(sCounter);

	for (int i = 0; i < n; ++i) {
		if (sccId[i] != -1) price_scc[sccId[i]] += atm[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int u: edge[i]) {
			if (sccId[i] != -1 && sccId[u] != -1) {
				child_scc[sccId[i]].push_back(sccId[u]);
			}
		}
	}

	for (int i = sCounter - 1; i >= 0; --i) {
		if (!value[i]) value[i] = price_scc[i];
		for (int u: child_scc[i]) {
			if (i != u) value[u] = max(value[u], price_scc[u] + value[i]);
		}
	}

	vector<bool> res_exist(sCounter, 0);
	while (p--) {
		cin >> a;
		a--;
		if (sccId[a] != -1) res_exist[sccId[a]] = 1;
	}

	int ans = -1;
	for (int i = 0; i < sCounter; ++i) {
		if (res_exist[i]) ans = max(ans, value[i]);
	}
	cout << ans;
}