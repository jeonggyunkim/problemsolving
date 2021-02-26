#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> i3;

int p[1001];

int find(int i) {
	if (i == p[i]) return i;
	return p[i] = find(p[i]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) p[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	vector<i3> edge;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> t;
			if (j > i) edge.push_back({t, i, j});
		}
		p[i] = i;
	}
	p[n] = n;

	for (int i = 0; i < n; ++i) {
		cin >> t;
		edge.push_back({t, i, n});
	}
	sort(edge.begin(), edge.end());

	long long ans = 0;

	for (i3 u: edge) {
		int a = find(get<1>(u));
		int b = find(get<2>(u));
		if (a != b) {
			ans += get<0>(u);
			merge(a, b);
		}
	}
	cout << ans;
}