#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	cin >> n >> m;

	int ans = 1;
	while (n--) {
		cin >> t;
		if (t) (ans *= t) %= m;
	}
	cout << ans % m;
}