#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q, t;
	cin >> n >> q;

	vector<int> cnt(32, 0);
	while (n--) {
		cin >> t;
		cnt[__builtin_ctz(t)]++;
	}

	while (q--) {
		cin >> t;
		int r = 1 << 30;
		int ind = 30, ans = 0;
		while (ind >= 0 && t) {
			if (t >= r) {
				int u = t >> ind, v = min(u, cnt[ind]);
				t -= (v << ind);
				ans += v;
			}
			r >>= 1;
			ind--;
		}
		if (t) cout << -1 << '\n';
		else cout << ans << '\n';
	}
}