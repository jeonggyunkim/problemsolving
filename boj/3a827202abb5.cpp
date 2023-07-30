#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ll d, p, q;
	cin >> d >> p >> q;

	ll ans = (1LL << 60);
	if (d / p < 100000) {
		for (ll i = 0; i < d / p + 2; ++i) {
			ll rem = d - i * p;
			if (rem > 0) {
				ll j = (rem + q - 1) / q;
				ans = min(ans, i * p + j * q);
			}
			else ans = min(ans, i * p);
		}
	}
	else if (d / q < 100000) {
		for (ll j = 0; j < d / q + 2; ++j) {
			ll rem = d - j * q;
			if (rem > 0) {
				ll i = (rem + p - 1) / p;
				ans = min(ans, i * p + j * q);
			}
			else ans = min(ans, j * q);
		}
	}
	else {
		for (ll i = 0; i < q; ++i) {
			ll rem = d - i * p;
			if (rem > 0) {
				ll j = (rem + q - 1) / q;
				ans = min(ans, i * p + j * q);
			}
			else ans = min(ans, i * p);
		}
	}
	cout << ans;
}