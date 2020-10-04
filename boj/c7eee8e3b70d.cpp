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

	long long a, b;
	cin >> a >> b;

	long long n = gcd(a, b);
	while (n--) cout << '1';
}