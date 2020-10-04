#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool check[55];
bool party[55];
vector<vector<int>> part;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	part.resize(m);

	queue<int> q;
	int num, t;
	cin >> num;
	while (num--) {
		cin >> t;
		check[t] = 1;
		q.push(t);
	}

	for (int i = 0; i < m; ++i) {
		cin >> num;
		while (num--) {
			cin >> t;
			part[i].push_back(t);
		}
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < m; ++i) {
			if (party[i]) continue;
			bool in = 0;
			for (int u: part[i]) {
				if (u == now) in = 1;
			}
			if (in) {
				party[i] = 1;
				for (int u: part[i]) {
					if (!check[u]) {
						check[u] = 1;
						q.push(u);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		if (!party[i]) ans++;
	}

	cout << ans;
}