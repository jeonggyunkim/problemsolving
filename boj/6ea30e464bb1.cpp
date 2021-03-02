#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		long long t, sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> t;
			t %= n;
			sum += t;
		}

		if (sum % n == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}