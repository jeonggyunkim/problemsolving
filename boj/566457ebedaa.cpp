#include <iostream>
using namespace std;

typedef long long ll;

ll sum(ll n) {
	ll ret = 0;
	ll prod = 1;

	while (prod <= n) {
		ll up = n / (prod * 10);
		ll now = (n / prod) % 10;
		ll down = n % prod;
		ret += up * 45 * prod;
		for (int i = 0; i < now; ++i) ret += i * prod;
		ret += (down + 1) * now;
		prod *= 10;
	}
	return ret;
}

int main() {
	ll a, b;
	cin >> a >> b;

	if (b < a) {
		cout << 0;
		return 0;
	}

	cout << sum(b) - sum(a - 1);
}