#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ii> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
		if (arr[i].first > arr[i].second) swap(arr[i].first, arr[i].second);
	}

	vector<vector<int>> edge(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (arr[i].first <= arr[j].first && arr[i].second <= arr[j].second) {
				edge[j].push_back(i);
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < n; ++i) {
		vector<int> d(n, -1);
		queue<ii> q;
		q.push(ii(i, 1));
		d[i] = 1;
		while (!q.empty()) {
			ii now = q.front(); q.pop();
			if (d[now.first] > now.second) continue;
			for (int u: edge[now.first]) {
				if (d[now.first] + 1 > d[u]) {
					d[u] = d[now.first] + 1;
					q.push(ii(u, d[now.first] + 1));
					ans = max(ans, d[u]);
				}
			}
		}
	}

	cout << ans;
}