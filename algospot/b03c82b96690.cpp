#include <iostream>
#include <vector>
#include <queue>
#define index(a) (a <= 'Z' ? a - 'A' : a - 'a' + 26)
#define INF 987654321
using namespace std;

int n, m, v;

bool find_increase(vector<vector<int>>& capacity, vector<vector<int>>& flow, int& totalFlow) {
	vector<int> p(v, -1);
	queue<int> q;
	p[0] = 0;
	q.push(0);

	while (!q.empty() && p[v - 1] == -1) {
		int now = q.front(); q.pop();
		for (int i = 0; i < v; ++i) {
			if (p[i] == -1 && capacity[now][i] - flow[now][i] > 0) {
				q.push(i);
				p[i] = now;
			}
		}
	}

	if (p[v - 1] == -1) return false;

	int amount = INF;
	for (int i = v - 1; i != 0; i = p[i]) {
		amount = min(amount, capacity[p[i]][i] - flow[p[i]][i]);
	}

	for (int i = v - 1; i != 0; i = p[i]) {
		flow[p[i]][i] += amount;
		flow[i][p[i]] -= amount;
	}
	totalFlow += amount;

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		bool imp = 0;
		cin >> n >> m;

		vector<int> wins(n);
		cin >> wins[0];
		int min_win = wins[0];
		for (int i = 1; i < n; ++i) {
			cin >> wins[i];
			min_win = max(min_win, wins[i] + 1);
		}

		v = n + m + 2;
		vector<vector<int>> capacity(v, vector<int>(v, 0)), flow(v, vector<int>(v, 0));

		int a, b;
		for (int i = 1; i <= m; ++i) {
			capacity[0][i] = 1;
			cin >> a >> b;
			capacity[i][m + 1 + a] = 1;
			capacity[i][m + 1 + b] = 1;
		}

		int totalFlow = 0;
		capacity[m + 1][v - 1] = min_win - wins[0];
		for (int i = 0; i < min_win - wins[0]; ++i) {
			if (!find_increase(capacity, flow, totalFlow)) imp = 1;
		}

		if (imp) {
			cout << -1 << '\n';
			continue;
		}

		for (int i = 1; i < n; ++i) capacity[m + 1 + i][v - 1] = min_win - wins[i] - 1;

		while (true) {
			while (find_increase(capacity, flow, totalFlow));

			if (totalFlow == m) {
				break;
			}
			else {
				min_win++;
				capacity[m + 1][v - 1]++;

				if (!find_increase(capacity, flow, totalFlow)) {
					imp = 1;
					break;
				}

				for (int i = 1; i < n; ++i) capacity[m + 1 + i][v - 1]++;
			}
		}

		if (imp) cout << -1 << '\n';
		else cout << min_win << '\n';
	}
}
