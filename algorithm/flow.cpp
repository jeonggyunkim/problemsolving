#include <bits/stdc++.h>
using namespace std;
#define INF 987654321


//flow
typedef tuple<int, int, int> iii;

int capacity[1002][1002];
int flow[1002][1002];
int s = 1000, f = 1001;
vector<vector<int>> edge(1002);
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


// MCMF
int c[202][202], f[202][202], w[202][202];
vector<vector<int>> edge(202);
const int S = 200, F = 201;

int ans = 0;
while (true) {
	vector<int> d(202, INF), p(202, -1);
	vector<bool> in(202, 0);
	queue<int> q;
	d[S] = 0; q.push(S);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		in[now] = 0;
		for (int u: adj[now]) {
			if (c[now][u] - f[now][u] > 0 && d[u] > d[now] + w[now][u]) {
				d[u] = d[now] + w[now][u];
				p[u] = now;
				if (!in[u]) {
					q.push(u);
					in[u] = 1;
				}
			}
		}
	}
	
	if (p[F] == -1) break;
	
	int flow = INF;
	for (int now = F; now != S; now = p[now]) {
		flow = min(flow, c[p[now]][now] - f[p[now]][now]);
	}
	
	for (int now = F; now != S; now = p[now]) {
		ans += flow * w[p[now]][now];
		f[p[now]][now] += flow;
		f[now][p[now]] -= flow;
	}
}


// 2 layer network
int bm[1010];
bool vis[1010];
vector<vector<int>> edge;

bool dfs(int a) {
	if (vis[a]) return 0;
	vis[a] = 1;
	
	for (int b: edge[a]) {
		if (bm[b] == -1 || dfs(bm[b])) {
			bm[b] = a;
			return 1;
		}
	}
	return 0;
}

int size = 0;
memset(bm, -1, sizeof(bm));
for (int i = 0; i < n; ++i) {
	memset(vis, 0, sizeof(vis));
	if (dfs(i)) size++;
}

cout << size;
