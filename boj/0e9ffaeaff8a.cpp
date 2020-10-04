#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		ll p, q, a, b, c, d;
		cin >> p >> q >> a >> b >> c >> d;
		ll coin = 0;
		coin += (q / c) * d;

		ll op = (p - coin) / (a + b);
		ll op2 = op - 1, op3 = op + 1;
		ll ans = -1;
		ans = max(ans, min(b * op + coin, -a * op + p));
		ans = max(ans, min(b * op2 + coin, -a * op2 + p));
		ans = max(ans, min(b * op3 + coin, -a * op3 + p));

		cout << ans << '\n';
	}
}