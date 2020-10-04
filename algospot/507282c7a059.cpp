#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long ans = 0;
	for (int k = 0; k <= n; ++k) {
		ans += (3 * k + n) * (n - k + 1) / 2;
	}
	cout << ans;
}
