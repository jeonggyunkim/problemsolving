#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 7; i <= min(n, 59); ++i) {
		vector<long long> res;
		if (isPrime(i)) {
			long long t = (1LL << i) - 1;
			for (long long j = 3; j * j <= t; j += 2) {
				if (t % j == 0) {
					t /= j;
					res.push_back(j);
				}
			}
			res.push_back(t);
		}
		if (res.size() > 1) {
			for (int i = 0; i < res.size(); ++i) {
				if (i != 0) printf(" * ");
				printf("%lld", res[i]);
			}
			printf(" = %lld", (1LL << i) - 1);
			printf(" = ( 2 ^ %d ) - 1\n", i);
		}
	}
}