#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

time_t start;
vector<long long> ans;

void print() {
	while (1) {
		bool change = 0;
		for (int i = 0; i < ans.size(); ++i) {
			if (change || ans[i] > 1e9) continue;
			for (int j = 2; j * j <= ans[i]; ++j) {
				if (ans[i] % j == 0) {
					ans[i] /= j;
					ans.push_back(j);
					change = 1;
					break;
				}
			}
		}
		if (!change) break;
	}

	sort(ans.begin(), ans.end());

	for (long long u: ans) cout << u << '\n';
}

long long pollard(__uint128_t n, int s) {
	__uint128_t x = 2;
	__uint128_t y = 2;
	__uint128_t d = 1;

	while (d == 1) {
		if (clock() - start > 0.9 * CLOCKS_PER_SEC) {
			ans.push_back(n);
			print();
			exit(0);
		}

		x = (x * x + s) % n;
		y = (y * y + s) % n;
		y = (y * y + s) % n;
		d = __gcd(x > y ? x - y : y - x, n);
	}

	return d;
}

int main() {
	long long n;
	cin >> n;
	
	if (n == 1) {
		cout << 1;
		return 0;
	}

	start = clock();

	while (n != 1) {
		long long div = pollard(n, 1);
		if (div != n) {
			ans.push_back(div);
			n /= div;
			continue;
		}
		div = pollard(n, 3);
		if (div != n) {
			ans.push_back(div);
			n /= div;
			continue;
		}
		div = pollard(n, 5);
		if (div != n) {
			ans.push_back(div);
			n /= div;
			continue;
		}
		else break;
	}
	if (n != 1) ans.push_back(n);

	print();
}