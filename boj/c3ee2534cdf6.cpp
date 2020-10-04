#include <iostream>
using namespace std;

typedef long long ll;

ll n, k;

ll low_cnt(ll t) {
	ll ret = 0;
	for (int i = 1; i <= n; ++i) {
		ret += min(t / i, n);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	ll low = 0, high = min((ll)n * n, (ll)10e9), mid;

	while (high - low > 1) {
		mid = (low + high) / 2;
		if (low_cnt(mid) >= k) high = mid;
		else low = mid;
	}

	cout << high;
}