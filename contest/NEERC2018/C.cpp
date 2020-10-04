#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, t;
	cin >> n;

	int stand;
	vector<int> z(100, 0);
	for (int i = 0; i < n; ++i) {
		cin >> t;
		int tt = t;
		int zero = 0;
		while (tt % 2 == 0) {
			tt /= 2;
			zero++;
		}
		if (i == 0) stand = tt;

		if (tt != stand) {
			cout << -1;
			return 0;
		}
		z[zero]++;
	}

	int ans = 0;
	int cnt = n;
	for (int i = 0; cnt != 1; ++i) {
		z[i + 1] += (z[i] + 1) / 2;
		cnt -= z[i] / 2;
		ans += z[i] % 2;
	}

	cout << ans;
}