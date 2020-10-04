#include <bits/stdc++.h>
using namespace std;

int n;
int tree[1000001];

int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(int i) {
	while (i <= n) {
		tree[i]++;
		i += (i & -i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, s;
	cin >> n >> m >> k >> s;

	int stuff[100001];
	for (int i = 0; i < n; ++i) {
		cin >> stuff[i];
		stuff[i]--;
	}

	vector<int> edge[100001];
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int dist[100001][101];
	memset(dist, -1, sizeof(dist));
	for (int t = 0; t < k; ++t) {
		queue<int> q;

		for (int i = 0; i < n; ++i) {
			if (stuff[i] == t) {
				q.push(i);
				dist[i][t] = 0;
			}
		}

		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int i : edge[now]) {
				if (dist[i][t] == -1) {
					dist[i][t] = dist[now][t] + 1;
					q.push(i);
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		sort(dist[i], dist[i] + k);
		int ans = 0;
		for (int j = 0; j < s; ++j) ans += dist[i][j];
		cout << ans << ' ';
	}
}