#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	long long c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a, b;
	long long p = 1, q = 1, r;
	cin >> b;
	for (int i = 1; i < n; ++i) {
		a = b;
		cin >> b;
		p *= a; q *= b;
		r = gcd(p, q);
		p /= r; q /= r;
		cout << p << '/' << q << '\n';
	}
}