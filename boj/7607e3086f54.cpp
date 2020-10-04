#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
#include <tuple>
#define INF 987654321
using namespace std;

typedef tuple<int, int, int> iii;

int capacity[401][401];
int flow[401][401];
int s = 1, f = 2;
vector<vector<int>> edge(401);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
		capacity[a][b]++;
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
