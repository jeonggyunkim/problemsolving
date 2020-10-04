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

	long long a, b, t;
	while (n--) {
		cin >> a >> b;
		while (a != 1) {
			t = (b + a - 1) / a;
			a = a * t - b;
			b = b * t;
			t = gcd(a, b);
			a /= t; b /= t;
		}
		cout << b << '\n';
	}
}