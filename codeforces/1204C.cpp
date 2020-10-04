#include <bits/stdc++.h>
using namespace std;

string adj[101];
int dist[101][101];

int n;

void bfs(int i) {
	queue<int> q;
	dist[i][i] = 0;
	q.push(i);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int j = 0; j < n; ++j) {
			if (adj[now][j] == '1' && dist[i][j] == -1) {
				dist[i][j] = dist[i][now] + 1;
				q.push(j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dist, -1, sizeof(dist));
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> adj[i];

	for (int i = 0; i < n; ++i) bfs(i);

	int m;
	cin >> m;
	vector<int> arr(m);

	for (int i = 0; i < m; ++i) {
		cin >> arr[i];
		arr[i]--;
	}

	int start = 0;
	vector<int> ans;
	while (start < m) {
		for (int check = min(n - 1, m - start - 1); check >= 1; check--) {
			if (dist[arr[start]][arr[start + check]] == check) {
				ans.push_back(arr[start]);
				start += check;
				break;
			}
		}
		if (start == m - 1) {
			ans.push_back(arr[start]);
			break;
		}
	}

	cout << ans.size() << '\n';
	for (int u: ans) cout << u + 1 << ' ';
}