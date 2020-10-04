#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> edge(n + 1);
	vector<int> time(n + 1);
	vector<int> maxtime(n + 1);

	int a, b;
	for (int i = 1; i <= n; ++i) {
		cin >> time[i];
		maxtime[i] = time[i];
		cin >> a;
		for (int j = 0; j < a; ++j) {
			cin >> b;
			edge[b].push_back(i);
		}
	}

	int ans = -1;
	for (int i = 1; i <= n; ++i) {
		if (ans < maxtime[i]) ans = maxtime[i];
		for (int u: edge[i]) {
			maxtime[u] = max(maxtime[u], maxtime[i] + time[u]);
		}
	}

	cout << ans;
}