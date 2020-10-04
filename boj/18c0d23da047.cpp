#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;
	vector<vector<ii>> edge(n + 1);

	int a, b, c;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b >> c;
		edge[a].push_back(ii(b, c));
		edge[b].push_back(ii(a, c));
	}
	vector<vector<int>> p(n + 1, vector<int>(17, 0));
	vector<vector<int>> mind(n + 1, vector<int>(17, 0));
	vector<vector<int>> maxd(n + 1, vector<int>(17, 0));
	vector<int> d(n + 1, -1);
	queue<int> q;

	p[1][0] = -1;
	d[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (ii u: edge[t]) {
			if (p[u.first][0] == 0) {
				p[u.first][0] = t;
				mind[u.first][0] = u.second;
				maxd[u.first][0] = u.second;
				d[u.first] = d[t] + 1;
				q.push(u.first);
			}
		}
	}
	p[1][0] = 0;

	for (int j = 1; j < 16; ++j) {
		for (int i = 1; i <= n; ++i) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			mind[i][j] = min(mind[i][j - 1], mind[p[i][j - 1]][j - 1]);
			maxd[i][j] = max(maxd[i][j - 1], maxd[p[i][j - 1]][j - 1]);
		}
	}

	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		int amin = 1 << 30, amax = -1;
		while (a != b) {
			if (d[a] > d[b]) {
				int j = 0, t = a;
				while (j < 17 && d[p[t][j]] >= d[b]) {
					a = p[t][j];
					amin = min(amin, mind[t][j]);
					amax = max(amax, maxd[t][j]);
					j++;
				}
			}
			else if (d[a] < d[b]) {
				int j = 0, t = b;
				while (j < 17 && d[p[t][j]] >= d[a]) {
					b = p[t][j];
					amin = min(amin, mind[t][j]);
					amax = max(amax, maxd[t][j]);
					j++;
				}
			}
			else {
				int t1 = a, t2 = b;
				a = p[t1][0]; b = p[t2][0];
				amin = min(amin, min(mind[t1][0], mind[t2][0]));
				amax = max(amax, max(maxd[t1][0], maxd[t2][0]));
				int j = 1;
				while (j < 17 && p[t1][j] != p[t2][j]) {
					a = p[t1][j]; b = p[t2][j];
					amin = min(amin, min(mind[t1][j], mind[t2][j]));
					amax = max(amax, max(maxd[t1][j], maxd[t2][j]));
					j++;
				}
			}
		}
		cout << amin << ' ' << amax << '\n';
	}
}