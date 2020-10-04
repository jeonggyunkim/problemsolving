#include <iostream>
using namespace std;

int main() {
	int n, p;
	cin >> n >> p;

	long long ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans *= i;
		ans %= p;
	}

	cout << ans << '\n';
}