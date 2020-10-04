#include <bits/stdc++.h>
using namespace std;
	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	
	while (tc--) {
		long long n, x, d, h;
		cin >> n >> x;
	
		long long maxd = -1, dec = -1;
		for (int i = 1; i <= n; ++i) {
			cin >> d >> h;
			maxd = max(maxd, d);
			dec = max(dec, d - h);
		}
	
		if (maxd >= x) {
			cout << 1 << '\n';
		}
		else {
			if (dec <= 0) cout << -1 << '\n';
			else {
				cout << (x - maxd + dec - 1) / dec + 1 << '\n';
			}
		}
	}
}