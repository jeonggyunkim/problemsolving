#include <iostream>
#include <cmath>
using namespace std;

bool isTri(long long t) {
	long long low = 0, high = 2 * (long long)sqrt(t) + 10;
	while (high - low != 1) {
		long long mid = (low + high) / 2;
		long long value = mid * (mid + 1) / 2;
		if (value < t) low = mid;
		else high = mid;
	}
	if ((high * (high + 1) / 2) == t) return 1;
	else return 0;
}

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

int main() {
	long long i = 144;
	while (1) {
		long long now = i * (2 * i - 1);
		if (isTri(now) && isPen(now)) {
			cout << now << endl;
			return 0;
		}
		i++;
	}
}