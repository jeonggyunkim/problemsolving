#include <iostream>
#include <vector>
#define N 1000000
using namespace std;

int main() {
	vector<bool> prime(N + 1, 1);
	prime[0] = prime[1] = 0;
	for (int i = 0; i * i <= N; ++i) {
		if (prime[i]) {
			for (int j = i * i; j <= N; j += i) {
				prime[j] = 0;
			}
		}
	}

	vector<int> primes;
	for (int i = 0; i <= N; ++i) {
		if (prime[i]) primes.push_back(i);
	}

	int ans;
	int len = 2;
	while (1) {
		int now = 0;
		for (int i = 0; i < len; ++i) now += primes[i];
		if (now >= N) break;
		
		for (int i = len; now < N && i < primes.size(); ++i) {
			if (prime[now]) ans = now;
			now += primes[i];
			now -= primes[i - len];
		}
		len++;
	}
	cout << ans << endl;
}