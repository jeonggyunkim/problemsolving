#include <iostream>
#include <cmath>
using namespace std;

bool isPen(long long t) {
	long long low = 0, high = (long long)sqrt(t) + 10;
	while (high - low != 1) {
		long long mid = (low + high) / 2;
		long long value = mid * (3 * mid - 1) / 2;
		if (value < t) low = mid;
		else high = mid;
	}
	if ((high * (3 * high - 1) / 2) == t) return 1;
	else return 0;
}

void canDif(long long n) {
	for (int len = 1; ; ++len) {
		long long m = n - 4 * len;
		m -= 3 * len * (len - 1) / 2;
		if (m < 0) break;
		if (m % (3 * len)) continue;
		else {
			long long num = m / (3 * len) + 1;
			long long low = num * (3 * num - 1) / 2;
			if (isPen(2 * low + n)) {
				cout << n << endl;
				exit(0);
			}
		}
	}
}

int main() {
	long long i = 1;
	while (1) {
		canDif(i * (3 * i - 1) / 2);
		i++;
	}
}