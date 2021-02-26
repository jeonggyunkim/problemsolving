#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> i3;

int p[2001 * 2001];
int x[2001], y[2001];

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

	int a, b, n, m;
	cin >> a >> b >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	for (int i = 1; i <= m; ++i) cin >> y[i];
	x[n + 1] = a;
	y[m + 1] = b;
	sort(x, x + n + 2);
	sort(y, y + m + 2);

	vector<i3> arr;
	for (int i = 0; i <= n; ++i) {
		arr.push_back({x[i + 1] - x[i], 0, i});
	}
	for (int i = 0; i <= m; ++i) {
		arr.push_back({y[i + 1] - y[i], 1, i});
	}
	for (int i = 0; i < (n + 1) * (m + 1); ++i) p[i] = i;
	sort(arr.begin(), arr.end());

	long long ans = 0;
	for (i3 u: arr) {
		if (get<1>(u)) {
			int index = get<2>(u) * (n + 1);
			for (int i = 0; i < n; ++i) {
				if (find(index + i) != find(index + i + 1)) {
					merge(index + i, index + i + 1);
					ans += get<0>(u);
				}
			}
		}
		else {
			int index = get<2>(u);
			for (int i = 0; i < m; ++i) {
				if (find(index + i * (n + 1)) != find(index + (i + 1) * (n + 1))) {
					merge(index + i * (n + 1), index + (i + 1) * (n + 1));
					ans += get<0>(u);
				}
			}
		}
	}
	cout << ans;
}