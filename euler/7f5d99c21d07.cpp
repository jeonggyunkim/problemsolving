#include <iostream>
using namespace std;

bool isPrime(unsigned int n) {
	if (n < 2) return 0;
	if (n % 2 == 0) {
		if (n == 2) return 1;
		else return 0;
	}
	int s = __builtin_ctz(n - 1);
	for (unsigned long long a: {2, 7, 61}) {
		if (a >= n) continue;
		int d = (n - 1) >> s;
		unsigned long long now = 1;
		while (d != 0) {
			if (d & 1) now = (now * a) % n;
			a = (a * a) % n;
			d >>= 1;
		}
		if (now == 1) goto success;
		for (int i = 0; i < s; ++i) {
			if (now == n - 1) goto success;
			now = (now * now) % n;
		}
		return 0;
		success:;
	}
	return 1;
}

int main() {
	int maxSeq = -1, ans;
	for (int a = -999; a <= 999; ++a) {
		for (int b = -1000; b <= 1000; ++b) {
			int i = 0;
			int val = i * i + a * i + b;
			while (val >= 1 && isPrime(val)) {
				i++;
				val = i * i + a * i + b;
			}
			if (i >= maxSeq) {
				maxSeq = i;
				ans = a * b;
			}
		}
	}
	cout << ans << endl;
}