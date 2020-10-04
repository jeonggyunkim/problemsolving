#include <iostream>
#define MOD 1000000007
using namespace std;

typedef unsigned long long ull;

ull gcd(ull a, ull b) {
	ull c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void mul(ull a[4], ull b[4]) {
	ull c[4];
	c[0] = (a[0] * b[0] + a[1] * b[2]) % MOD;
	c[1] = (a[0] * b[1] + a[1] * b[3]) % MOD;
	c[2] = (a[2] * b[0] + a[3] * b[2]) % MOD;
	c[3] = (a[2] * b[1] + a[3] * b[3]) % MOD;
	for (int i = 0; i < 4; ++i) a[i] = c[i];
}

void pow(ull a[4], ull b) {
	if (b == 1) return;
	if (b & 1) {
		ull c[4];
		for (int i = 0; i < 4; ++i) c[i] = a[i];
		pow(a, b - 1);
		mul(a, c);
	}
	else {
		mul(a, a);
		pow(a, b / 2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ull a, b;
	cin >> a >> b;
	ull c = gcd(a, b);

	ull base[4] = {0, 1, 1, 1};
	pow(base, c);

	cout << base[1];
}