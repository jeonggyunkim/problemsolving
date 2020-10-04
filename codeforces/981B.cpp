#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	ii x[100000];
	ii y[100000];

	int a, b;
	cin >> a >> b;
	for (int i = 0; i < n; ++i) cin >> x[i].first >> x[i].second;
	cin >> m;
	for (int i = 0; i < m; ++i) cin >> y[i].first >> y[i].second;
	sort(x, x + n);
	sort(y, y + m);

	int i1 = 0, i2 = 0;
	long long tot = 0;
	while (i1 < n && i2 < m) {
		if (x[i1].first == y[i2].first) {
			tot += max(x[i1].second, y[i2].second);
			i1++; i2++;
		}
		else if (x[i1].first < y[i2].first) {
			tot += x[i1].second;
			i1++;
		}
		else {
			tot += y[i2].second;
			i2++;
		}
	}
	while (i1 < n) tot += x[i1++].second;
	while (i2 < m) tot += y[i2++].second;

	cout << tot;
}