#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int a, b, c;
		cin >> a >> b >> c;

		int ans = 0;
		for (int x = 1; x <= a; ++x) {
			for (int y = 1; y <= b; ++y) {
				for (int z = 1; z <= c; ++z) {
					if (x % y == y % z && y % z == z % x) {
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}