#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n + 1);
	vector<int> pointing(n + 1, 0);

	int a, b;
	while (m--) {
		cin >> a >> b;
		edge[a].push_back(b);
		pointing[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; ++i) {
		if (pointing[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int t = pq.top(); pq.pop();
		cout << t << ' ';
		for (int u: edge[t]) {
			pointing[u]--;
			if (pointing[u] == 0) pq.push(u);
		}
	}
}