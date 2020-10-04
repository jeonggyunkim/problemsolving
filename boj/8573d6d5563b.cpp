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

int power(int base, int index, int mod) {
	long long ret = 1;
	while (index != 0) {
		if (index & 1) ret = (ret * base) % mod;
		base = ((long long)base * base) % mod;
		index >>= 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int p, a;
	while (cin >> p >> a, p || a) {
		if (!isPrime(p) && power(a, p, p) == a) cout << "yes\n";
		else cout << "no\n";
	}
}