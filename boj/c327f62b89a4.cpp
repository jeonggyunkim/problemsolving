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
	int tc;
	cin >> tc;
	while (tc--) {
		long long a, b;
		cin >> a >> b;
		cout << a * b / gcd(a, b) << '\n';
	}
}