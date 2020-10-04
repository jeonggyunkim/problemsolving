#include <iostream>
#include <vector>
#define N 100000000
using namespace std;

int main() {
	vector<bool> prime(N + 1, 1);

	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= N; ++i) {
		if (prime[i]) {
			for (int j = i * i; j <= N; j += i) {
				prime[j] = 0;
			}
		}
	}
	
	int i = 10;
	int cnt = 0;
	int sum = 0;
	while (cnt != 11) {
		if (prime[i]) {
			int p = 1;
			int j = i / 10;
			while (j) {
				if (!prime[j]) goto fail;
				j /= 10;
				p *= 10;
			}
			while (p != 1) {
				if (!prime[i % p]) goto fail;
				p /= 10;
			}
			cnt++;
			sum += i;
		}
		fail:;
		i++;
	}
	cout << sum << endl;
}