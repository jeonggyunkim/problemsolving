#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int c;
		cin >> c;

		long long ans = 1, lcm = 1;
		for (int i = 0; i < c; ++i) {
			int p, a;
			cin >> p >> a;
			long long now = 0, t = 1;
			for (int j = 0; j < a; ++j) {
				(now += t) %= MOD;
				(t *= p) %= MOD;
			}
			(lcm *= t) %= MOD;
			(t *= (a + 1)) %= MOD;
			(now += t) %= MOD;
			(ans *= now) %= MOD;
		}
		(ans += lcm) %= MOD;
		cout << ans << '\n';
	}
}