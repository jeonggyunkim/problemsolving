#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int ans = 0;
	ans += 7 * (c / (7 * a + b));
	c %= (7 * a + b);
	ans += min(7, (c + a - 1) / a);
	cout << ans;
}