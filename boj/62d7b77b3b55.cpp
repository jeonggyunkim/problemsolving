#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int b, x, y;
		cin >> b >> x >> y;

		int digit[30] = {};
		for (int i = 0; x || y; ++i) {
			digit[i] = (x % b + y % b) % b;
			x /= b; y /= b;
		}

		int ans = 0, p = 1;
		for (int i = 0; i < 30; ++i) {
			ans += p * digit[i];
			p *= b;
		}
		cout << ans << '\n';
	}
}