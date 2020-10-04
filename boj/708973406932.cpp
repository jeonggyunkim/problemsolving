#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc, n, k;
	cin >> tc;

	while (tc--) {
		cin >> n >> k;
		cout << !((n - k) & ((k - 1) / 2)) << '\n';
	}
}