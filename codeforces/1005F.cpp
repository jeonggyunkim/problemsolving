#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

void inc(int n, vector<int>& index, vector<vector<int>>& to_change, vector<bool>& select) {
	int p = index[n];
	index[n] = (index[n] + 1) % to_change[n].size();
	select[to_change[n][p]] = 0;
	select[to_change[n][index[n]]] = 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int a, b;
	vector<vector<ii>> edge(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		edge[a].push_back(ii(b, i));
		edge[b].push_back(ii(a, i));
	}

	vector<int> d(n + 1, -1);

	queue<int> q;
	q.push(1);
	d[1] = 0;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (ii u: edge[t]) {
			if (d[u.first] == -1) {
				q.push(u.first);
				d[u.first] = d[t] + 1;
			}
		}
	}

	vector<bool> select(m);
	vector<vector<int>> to_change;

	for (int i = 1; i <= n; ++i) {
		vector<int> con;
		for (ii u: edge[i]) {
			if (d[u.first] == d[i] - 1) {
				con.push_back(u.second);
			}
		}
		if (i != 1) select[con[0]] = 1;
		if (con.size() > 1 && to_change.size() < 20) {
			to_change.push_back(con);
		}
	}

	int ans = 1;
	for (int i = 0; i < to_change.size(); ++i) {
		ans *= to_change[i].size();
		ans = min(k, ans);
	}
	cout << ans << '\n';

	vector<int> index(to_change.size(), 0);
	for (int i = 0; i < ans; ++i) {
		for (int j = 0; j < m; ++j) cout << select[j];
		cout << '\n';

		if (i == ans - 1) break;
		inc(0, index, to_change, select);
		int j = 0;
		while (j < index.size() - 1 && index[j] == 0) {
			inc(j + 1, index, to_change, select);
			j++;
		}
	}
}