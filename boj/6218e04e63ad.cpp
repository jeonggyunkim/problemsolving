#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;

	vector<vector<ii>> edge(v);
	int a, b, c;
	for (int i = 0; i < e; ++i) {
		cin >> a >> b >> c;
		a--; b--;
		edge[a].push_back(ii(c, b));
		edge[b].push_back(ii(c, a));
	}

	vector<bool> add(v, 0);
	priority_queue<ii, vector<ii>, greater<ii>> pq;

	pq.push(ii(0, 0));

	int ans = 0;
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		if (add[now.second]) continue;
		ans += now.first;
		add[now.second] = 1;
		for (ii e: edge[now.second]) if (!add[e.second]) pq.push(e);
	}

	cout << ans;
}