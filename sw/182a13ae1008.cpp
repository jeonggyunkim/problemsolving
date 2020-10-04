#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n, t;
		cin >> n;

		int cnt[3][3] = {};
		for (int i = 1; i <= n; ++i) {
			cin >> t;
			cnt[i % 3][t % 3]++;
		}

		int ans = 0;
		t = min(cnt[0][1], cnt[1][0]);
		cnt[0][1] -= t; cnt[1][0] -= t;
		ans += t;

		t = min(cnt[0][2], cnt[2][0]);
		cnt[0][2] -= t; cnt[2][0] -= t;
		ans += t;

		t = min(cnt[1][2], cnt[2][1]);
		cnt[1][2] -= t; cnt[2][1] -= t;
		ans += t;
		
		ans += 2 * max(cnt[0][1], cnt[1][0]);

		cout << '#' << test << ' ' << ans << '\n';
	}
}
