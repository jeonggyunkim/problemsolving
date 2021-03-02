#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, d;
		cin >> n >> d;

		int v, f, c, ans = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v >> f >> c;
			if (v * f >= c * d) ans++;
		}
		cout << ans << '\n';
	}
}