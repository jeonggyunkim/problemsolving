#include <iostream>
using namespace std;

int main() {
	int n, t, u, ans = 0;
	cin >> n;

	u = 0;
	while (n--) {
		cin >> t;
		if (t != u + 1) ans += t;
		u = t;
	}
	cout << ans;
}