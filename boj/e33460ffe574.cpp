#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int l, n, t;
		cin >> l >> n;
		int mi = -1, ma = -1;
		while (n--) {
			cin >> t;
			ma = max(ma, max(l - t, t));
			mi = max(mi, min(l - t, t));
		}
		cout << mi << ' ' << ma << '\n';
	}
}