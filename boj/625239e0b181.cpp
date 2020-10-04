#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int d, m;
	cin >> d >> m;

	long long t, cm = 1, cd;
	for (int i = 0; i < d; ++i) {
		cin >> t;
		cm = cm * t / __gcd(cm, t);
		if (cm > 1e9) {
			cout << 0;
			return 0;
		}
	}

	for (int i = 0; i < d; ++i) {
		cin >> t;
		if (i == 0) cd = t;
		else cd = __gcd(cd, t);
	}
	
	if (cd % cm == 0) {
		t = cd / cm;

		int ans = 0;
		for (int i = 1; i * i <= t; ++i) {
			if (t % i == 0) ans += 2;
			if (i * i == t) ans--;
		}
		cout << ans;
	}
	else cout << 0;
}