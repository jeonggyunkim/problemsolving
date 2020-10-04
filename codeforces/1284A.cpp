#include <bits/stdc++.h>
using namespace std;

string a[22], b[22];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];

	int tc, t;
	cin >> tc;
	while (tc--) {
		cin >> t;
		t--;
		cout << a[t % n] << b[t % m] << '\n';
	}
}