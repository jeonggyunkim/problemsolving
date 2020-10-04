#include <iostream>
#include <vector>
#include <queue>
#define op(n) ((n & 1) ?  n - 1 : n + 1)
using namespace std;

typedef pair<int, int> ii;

vector<vector<int>> edge;

bool use(int i, vector<char>& used) {
	queue<int> q; q.push(i);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (used[now] == -1) return 0;

		used[now] = 1;
		used[op(now)] = -1;
		for (int u : edge[now]) {
			if (used[u] == 1) return 0;
			else if (used[u] == 0) {
				used[u] = -1;
				used[op(u)] = 1;
				q.push(op(u));
			}
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		n *= 2;

		vector<ii> time(n);
		edge.clear(); edge.resize(n);
		vector<char> used(n, 0);

		for (int i = 0; i < n; ++i) {
			cin >> time[i].first >> time[i].second;
			for (int j = 0; j < i; ++j) {
				if (time[i].second > time[j].first && time[j].second > time[i].first) {
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}

		bool pos = 1;
		for (int i = 0; i < n; ++i) if (used[i] == 0) {
			vector<char> used_temp = used;

			bool b = use(i, used_temp);
			if (!b) {
				used_temp = used;
				b = use(op(i), used_temp);
				if (!b) {
					pos = 0;
					cout << "IMPOSSIBLE\n";
					break;
				}
			}
			used = used_temp;
		}

		if (pos) {
			cout << "POSSIBLE\n";
			for (int i = 0; i < n; ++i) if (used[i] == 1) {
				cout << time[i].first << ' ' << time[i].second << '\n';
			}
		}
	}
}
