#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct circle {
	int x; int y; int r;
};

int relation(circle& a, circle& b) {
	int d = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	int R = (a.r + b.r) * (a.r + b.r);
	if (R < d) return 0;
	else if (a.r > b.r) return 1;
	else return -1;
}

void make_tree(vector<vector<int>>& edge, vector<int>& rel, vector<vector<int>>& who, int now) {
	for (int i : who[now]) rel[i]--;

	for (int i : who[now]) {
		if (rel[i] == 0) {
			edge[i].push_back(now);
			edge[now].push_back(i);
			make_tree(edge, rel, who, i);
		}
	}
	rel[now] = -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		vector<circle> c(n);
		for (int i = 0; i < n; ++i) {
			cin >> c[i].x >> c[i].y >> c[i].r;
		}

		vector<int> rel(n, 0);
		vector<vector<int>> who(n);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int r = relation(c[i], c[j]);
				if (r == 1) {
					rel[j]++;
					who[i].push_back(j);
				}
				else if (r == -1) {
					rel[i]++;
					who[j].push_back(i);
				}
			}
		}

		vector<vector<int>> edge(n);
		int deepest = 0, di = 0;
		for (int i = 0; i < n; ++i) {
			if (rel[i] > deepest) {
				deepest = rel[i];
				di = i;
			}
		}

		make_tree(edge, rel, who, 0);

		queue<int> q;
		vector<int> depth(n, -1);
		depth[di] = 0; q.push(di);
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int u : edge[now]) {
				if (depth[u] == -1) {
					depth[u] = depth[now] + 1;
					q.push(u);
				}
			}
		}

		deepest = 0;
		for (int i = 0; i < n; ++i) {
			if (depth[i] > deepest) deepest = depth[i];
		}
		cout << deepest << '\n';
	}
}
