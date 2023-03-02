#include <iostream>
#include <algorithm>
using namespace std;

int a[200000], b[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];

	sort(a, a + n, greater<int>());
	sort(b, b + m);

	long long ans = 0;
	for (int i = 0; i < min(n, m); ++i) {
		if (a[i] - b[i] >= 0) ans += a[i] - b[i];
	}
	cout << ans << '\n';
}