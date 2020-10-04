#include <iostream>
#define N 10000005
using namespace std;

bool notprime[N];

int main() {
	for (int i = 2; i * i < N; ++i) {
		if (!notprime[i]) {
			for (int j = i * i; j < N; j += i) notprime[j] = 1;
		}
	}

	long long a, b;
	cin >> a >> b;

	int ans = 0, maxp = 100;
	for (long long i = 2; i < N; ++i) {
		if (notprime[i]) continue;
		long long now = i * i;
		int p = 2;
		while (p <= maxp && now <= b) {
			if (now >= a) ans++;
			now *= i;
			p++;
		}
		maxp = p - 1;
		if (maxp == 1) break;
	}

	cout << ans;
}