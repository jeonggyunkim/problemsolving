#include <iostream>
#define MOD 1000000007
using namespace std;

long long pow(long long a, long long b, long long m) {
	if (b == 1) return a;
	long long c = pow(a, b / 2, m);
	if (b % 2 == 0) return (c * c) % m;
	else {
		c = (c * c) % m;
		c = (c * a) % m;
		return c;
	}
}

int main() {
	long long N, K;
	cin >> N >> K;

	long long r1 = 1;
	long long r2 = 1;

	for (int i = 1; i <= N; ++i) r1 = (r1 * i) % MOD;
	for (int i = 1; i <= K; ++i) r2 = (r2 * i) % MOD;
	for (int i = 1; i <= N - K; ++i) r2 = (r2 * i) % MOD;

	r2 = pow(r2, MOD - 2, MOD);
	cout << (r1 * r2) % MOD;
}