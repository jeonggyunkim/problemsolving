#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int a, b;
	cin >> a >> b;

	long long ans = a;
	ans *= b;
	ans /= gcd(a, b);
	cout << ans;
}