#include <iostream>
using namespace std;

typedef pair<int, int> ii;

int input[100010];
ii stree[400010];

ii build(int l, int r, int i) {
	if (l == r) {
		stree[i] = ii(l, l);
		return stree[i];
	}
	ii i1 = build(l, (l + r) >> 1, (i << 1) + 1), i2 = build(((l + r) >> 1) + 1, r, (i << 1) + 2);
	stree[i].first = input[i1.first] > input[i2.first] ? i2.first : i1.first;
	stree[i].second = input[i1.second] < input[i2.second] ? i2.second : i1.second;
	return stree[i];
}

ii find(int l, int r, int ll, int rr, int i) {
	if (l > rr || r < ll) return ii(-1, -1);
	if (ll >= l && rr <= r) return stree[i];
	ii i1 = find(l, r, ll, (ll + rr) >> 1, (i << 1) + 1), i2 = find(l, r, ((ll + rr) >> 1) + 1, rr, (i << 1) + 2);
	if (i1.first == -1) return i2;
	if (i2.first == -1) return i1;
	ii t;
	t.first = input[i1.first] > input[i2.first] ? i2.first : i1.first;
	t.second = input[i1.second] < input[i2.second] ? i2.second : i1.second;
	return t;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> input[i];
	build(0, n - 1, 0);

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		ii t = find(a, b, 0, n - 1, 0);
		cout << input[t.first] << ' ' << input[t.second] << '\n';
	}
}