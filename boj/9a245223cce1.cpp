#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define N 1002
using namespace std;

int c[N][N], f[N][N], w[N][N];
vector<vector<int>> edge(N);
int S, F;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	F = n - 1;

	int a, b, ww;
	while (m--) {
		cin >> a >> b >> ww;
		a--; b--;
		c[a][b] = 1;
		w[a][b] = ww;
		c[b][a] = 1;
		w[b][a] = ww;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int ans = 0;
	int totalFlow = 0;
	while (totalFlow < 2) {
		vector<int> d(N, INF), p(N, -1);
		vector<bool> in(N, 0);
		queue<int> q;
		d[S] = 0; q.push(S);
		while (!q.empty()) {
			int now = q.front(); q.pop();
			in[now] = 0;
			for (int u: edge[now]) {
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
		
		for (int now = F; now != S; now = p[now]) {
			ans += w[p[now]][now];
			f[p[now]][now] += 1;
			f[now][p[now]] -= 1;
			if (f[p[now]][now] == 1) {
				w[now][p[now]] *= -1;
			}
			else {
				w[p[now]][now] *= -1;
			}
		}
		totalFlow += 1;
	}
	cout << ans;
}