#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> edge(n);
	int a, b;
	while (m--) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	vector<ii> arr;
	for (int i = 0; i < n; ++i) {
		arr.push_back(ii(edge[i].size(), i));
	}

	sort(arr.begin(), arr.end());

	vector<int> len(n);
	for (int i = n - 1; i >= 0; --i) {
		int now = arr[i].second;
		int loc = 1;
		for (int u: edge[now]) {
			if (edge[u].size() > arr[i].first) {
				loc = max(loc, len[u] + 1);
			}
		}
		len[now] = loc;
	}

	int ans = -1;
	for (int i = 0; i < n; ++i) ans = max(ans, len[i]);
	cout << ans;
}
