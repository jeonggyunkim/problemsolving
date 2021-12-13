#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int x[400], y[400];
int capacity[1202][1202];
int flow[1202][1202];
vector<vector<int>> edge(1202);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(flow, 0, sizeof(flow));
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> arr;
	int mx = -1;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		mx = max(mx, y[i]);
		arr.push_back({x[i], y[i]});
	}

	sort(arr.begin(), arr.end());
	priority_queue<int> pq;
	int idx = 0, cnt = 0;
	for (int i = 1; i <= mx; ++i) {
		while (idx < arr.size() && arr[idx].first == i) {
			pq.push(-arr[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			cnt++; pq.pop();
			while (!pq.empty() && -pq.top() <= i) pq.pop();
		}
	}

	int s = 2 * mx + n;
	int f = s + 1;
	for (int i = 0; i < mx; ++i) {
		edge[i].push_back(i + mx);
		edge[i + mx].push_back(i);
		capacity[i][i + mx] = 1;
	}

	for (int i = 0; i < m; ++i) {
		edge[2 * mx + i].push_back(f);
		edge[f].push_back(2 * mx + i);
		capacity[2 * mx + i][f] = 1;
		for (int j = x[i]; j <= y[i]; ++j) {
			edge[mx + j - 1].push_back(2 * mx + i);
			edge[2 * mx + i].push_back(mx + j - 1);
			capacity[mx + j - 1][2 * mx + i] = 1;
		}
	}
	for (int i = m; i < n; ++i) {
		edge[s].push_back(2 * mx + i);
		edge[2 * mx + i].push_back(s);
		capacity[s][2 * mx + i] = 1;
		for (int j = x[i]; j <= y[i]; ++j) {
			edge[2 * mx + i].push_back(j - 1);
			edge[j - 1].push_back(2 * mx + i);
			capacity[2 * mx + i][j - 1] = 1;
		}
	}

	int totalFlow = 0;
	int p[1202];

	while (1) {
		memset(p, -1, sizeof(p));
		queue<int> q;
		p[s] = s;
		q.push(s);

		while (!q.empty() && p[f] == -1) {
			int now = q.front(); q.pop();
			for (int u: edge[now]) {
				if (p[u] == -1 && capacity[now][u] - flow[now][u] > 0) {
					q.push(u);
					p[u] = now;
				}
			}
		}

		if (p[f] == -1) break;

		for (int i = f; i != s; i = p[i]) {
			flow[p[i]][i]++;
			flow[i][p[i]]--;
		}
		totalFlow++;
	}

	cout << cnt << '\n';
	cout << totalFlow << '\n';
}