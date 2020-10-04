#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 3; ++i) {
		long long n, t;
		cin >> n;

		__int128_t ans = 0;
		while (n--) {
			cin >> t;
			ans += t;
		}
		if (ans > 0) cout << "+\n";
		else if (ans == 0) cout << "0\n";
		else cout << "-\n";
	}
}