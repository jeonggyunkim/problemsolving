#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
vector<int> p;

int find(int n) {
	if (n == p[n]) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) p[b] = a;
}

int maxUpper(vector<pair<int, pair<int, int>>>& edge, int s) {
	for (int i = 0; i < v; ++i) p[i] = i;

	for (int i = s; i < e; ++i) {
		merge(edge[i].second.first, edge[i].second.second);

		if (find(0) == find(v - 1)) {
			return edge[i].first - edge[s].first;
		}
	}
	return -1;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> v >> e;

		vector<pair<int, pair<int, int>>> edge(e);
		for (int i = 0; i < e; ++i) {
			cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
		}
		p.clear(); p.resize(v);

		sort(edge.begin(), edge.end());

		int ans = 987654321;
		for (int i = 0; i < e; ++i) {
			if (i != 0 && edge[i].first == edge[i - 1].first) continue;
			int t = maxUpper(edge, i);
			if (t == -1) break;
			ans = min(ans, t);
		}
		cout << ans << '\n';
	}
}
