#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	while (n >= m) n -= m;

	int ans = 1;
	for (int i = 2; i <= n; ) {
		if (n % i == 0 && m % i == 0) {
			ans *= i;
			n /= i;
			m /= i;
		}
		else ++i;
	}

	if (n == 0) cout << 0;
	else {
		cout << ans * (m - 1);
	}
}