#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	int m, n;
	cin >> m >> n;

	int ans = 987654321;
	int sum = 0;
	for (int i = m; i <= n; ++i) {
		if (isPrime(i)) {
			ans = min(ans, i);
			sum += i;
		}
	}
	if (ans = 987654321) cout << -1;
	else {
		cout << ans << '\n';
		cout << sum;
	}
}