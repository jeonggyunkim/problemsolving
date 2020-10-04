#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		int ans = 0;
		for (int i = 1; i * i <= n; ++i) {
			if (n % i == 0) {
				if (__gcd(n / i, i) == 1) ans++;
			}
		}
		cout << ans << '\n';
	}
}
