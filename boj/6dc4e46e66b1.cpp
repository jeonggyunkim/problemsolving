#include <iostream>
#include <cmath>
using namespace std;

long long phi(long long n) {
	long long ret = n;
	if (n % 2 == 0) {
		while (n % 2 == 0) n /= 2;
		ret /= 2;
	}
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			ret -= ret / i;
		}
	}
	if (n != 1) ret -= ret / n;
	return ret;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;
	cout << phi(n);
}