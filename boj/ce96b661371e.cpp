#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, a, b;
	cin >> n;
	long long ans = 0, last = -1e9 - 10;
	while (n--) {
		cin >> a >> b;
		ans += b - a;
		ans -= max(0LL, min(last, b) - a);
		last = max(last, b);
	}
	cout << ans;
}