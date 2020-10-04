#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int p[99];

int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) p[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n, n) {
		for (int i = 0; i < n; ++i) p[i] = i;

		vector<tuple<int, int, int>> edge;
		for (int i = 1; i < n; ++i) {
			char a, b;
			int k, d;
			cin >> a >> k;
			for (int j = 0; j < k; ++j) {
				cin >> b >> d;
				edge.push_back({d, a - 'A', b - 'A'});
			}
		}

		int ans = 0;
		sort(edge.begin(), edge.end());
		for (int i = 0; i < edge.size(); ++i) {
			if (find(get<1>(edge[i])) != find(get<2>(edge[i]))) {
				ans += get<0>(edge[i]);
				merge(get<1>(edge[i]), get<2>(edge[i]));
			}
		}
		cout << ans << '\n';
	}
}