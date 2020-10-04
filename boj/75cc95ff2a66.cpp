#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> iii;

vector<int> edge[200010];
vector<int> path;
bool team[200010];
int p[200010];
vector<iii> center;

void dfs(int i, int par) {
	path.push_back(i);
	p[i] = par;
	if (team[i]) {
		if (path.size() % 2 == 0) {
			cout << "NO";
			exit(0);
		}
		if (par != -1) {
			int ind = path.size() / 2;
			center.push_back({ind, path[ind], path[ind + 1]});
		}
	}
	for (int u: edge[i]) {
		if (u != par) dfs(u, i);
	}
	path.pop_back();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (m == 1) {
		cout << "YES\n1";
		return 0;
	}

	int a, b;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int start;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		team[a] = 1;
		start = a;
	}

	dfs(start, -1);

	sort(center.begin(), center.end());

	for (int i = 1; i < m - 1; ++i) {
		if (get<0>(center[i - 1]) == get<0>(center[i]) && get<1>(center[i - 1]) != get<1>(center[i])) {
			cout << "NO";
			return 0;
		}
	}

	int ind = m - 2;
	int d = get<0>(center[ind]);
	int now = get<1>(center[ind]);
	while (d) {
		while (ind >= 0 && get<0>(center[ind]) >= d) ind--;
		while (ind >= 0 && get<0>(center[ind]) == d - 1) {
			if (get<2>(center[ind]) == now) {
				cout << "NO";
				return 0;
			}
			ind--;
		}
		d--;
		now = p[now];
	}

	cout << "YES\n";
	cout << get<1>(center[m - 2]);
}