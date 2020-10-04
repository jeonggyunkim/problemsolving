#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
#include <tuple>
#define INF 987654321
using namespace std;

typedef tuple<int, int, int> iii;

int capacity[801][801];
int flow[801][801];
int s = 401, f = 2;
vector<vector<int>> edge(801);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		edge[400 + a].push_back(b);
		edge[b].push_back(400 + a);
		edge[400 + b].push_back(a);
		edge[a].push_back(400 + b);
		capacity[400 + a][b]++;
		capacity[400 + b][a]++;
	}
	for (int i = 1; i <= n; ++i) {
		edge[i].push_back(400 + i);
		edge[400 + i].push_back(i);
		capacity[i][400 + i] = 1;
	}
	
	int totalFlow = 0;
	int p[1002];
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

		int amount = INF;
		for (int i = f; i != s; i = p[i]) {
			amount = min(amount, capacity[p[i]][i] - flow[p[i]][i]);
		}

		for (int i = f; i != s; i = p[i]) {
			flow[p[i]][i] += amount;
			flow[i][p[i]] -= amount;
		}
		totalFlow += amount;
	}
	cout << totalFlow;
}
