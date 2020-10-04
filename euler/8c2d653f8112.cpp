#include <iostream>
#include <vector>
#include <algorithm>
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
	int len = 2;
	while (1) {
		for (int i = 1; i < len; ++i) {
			vector<int> arr(len, 0);
			for (int j = 0; j < i; ++j) arr[j] = 1;
			do {
				int p = 1;
				for (int j = 0; j < len - i; ++j) p *= 10;
				for (int j = 0; j < p; ++j) {
					int k = j;
					int sum = 0;
					int base = 0;
					for (int l = 0; l < len; ++l) {
						sum *= 10;
						base *= 10;
						if (arr[l] == 1) sum += 1;
						else {
							base += k % 10;
							k /= 10;
						}
					}
					int cnt = 0;
					for (int l = (arr[0] == 1 && base < sum) ? 1 : 0; l < 10; ++l) {
						if (isPrime(base + sum * l)) cnt++;
					}
					if (cnt == 8) {
						if (arr[0] == 1 && base < sum) {
							cout << base + sum << endl;
						}
						else cout << base << endl;
						return 0;
					}
				}
			} while (prev_permutation(arr.begin(), arr.end()));
		}
		len++;
	}
}