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

	for (int i = 3; i <= N; i += 2) {
		if (!prime[i]) {
			int j = 1;
			int find = 0;
			while (i - 2 * j * j >= 1) {
				if (prime[i - 2 * j * j]) find = 1;
				j++;
			}
			if (!find) {
				cout << i << endl;
				return 0;
			}
		}
	}
}