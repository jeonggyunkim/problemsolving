#include <iostream>
using namespace std;

long long jos(long long n, int k) {
	if (n == 1) return 0;
	if (k == 1) return n - 1;
	if (k <= n) {
		long long n_ = n - n / k;
		long long ret = jos(n_, k) - n % k;
		if (ret < 0) ret += n_;
		return (k * (ret % n_)) / (k - 1);
	}
	else {
		return (jos(n - 1, k) + k) % n;
	}
}

int main() {
	long long n, k;
	cin >> n >> k;

	cout << jos(n, k) + 1;
}