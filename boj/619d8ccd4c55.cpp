#include <iostream>
#include <vector>
#define N 4000000
using namespace std;

int count(int n, int p) {
	int ret = 0;
	while (n) {
		n /= p;
		ret += n;
	}
	return ret;
}

int main() {
	int n, k, m;
	cin >> n >> k >> m;

	vector<int> prime(N + 1, 1);
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= N; ++i) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= N; j += i) prime[j] = 0;
	}

	long long ans = 1;
	for (int i = 0; i <= n; ++i) {
		if (prime[i]) {
			int t = count(n, i) - count(n - k, i) - count(k, i);
			for (int j = 0; j < t; ++j) {
				ans *= i;
				ans %= m;
			}
		}
	}
	cout << ans;
}