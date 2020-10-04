#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int p[1001];

int find(int i) {
	if (i == p[i]) return i;
	return p[i] = find(p[i]);
}

int merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) p[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) p[i] = i;

	vector<tuple<int, int, int>> arr(m);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		arr[i] = {c, a, b};
	}

	sort(arr.begin(), arr.end());

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		if (find(get<1>(arr[i])) != find(get<2>(arr[i]))) {
			ans += get<0>(arr[i]);
			merge(get<1>(arr[i]), get<2>(arr[i]));
		}
	}
	cout << ans;
}