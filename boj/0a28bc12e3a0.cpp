#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int sum = 0, ans = 999, t;
		for (int i = 0; i < 7; ++i) {
			cin >> t;
			if (t % 2 == 0) {
				sum += t;
				ans = min(ans, t);
			}
		}
		cout << sum << ' ' << ans << '\n';
	}
}