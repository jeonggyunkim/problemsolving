#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, t, mx = -1e6 - 10, mn = 1e6 + 10;
		cin >> n;

		while (n--) {
			cin >> t;
			mx = max(mx, t);
			mn = min(mn, t);
		}
		cout << mn << ' ' << mx << '\n';
	}
}