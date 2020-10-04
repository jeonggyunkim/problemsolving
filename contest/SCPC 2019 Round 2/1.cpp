#include <iostream>
#include <vector>
#define N 30010
using namespace std;

int ten[6] = {1, 10, 100, 1000, 10000, 100000};


int len(int n) {
	int ret = 0;
	while (n) {
		ret++;
		n /= 10;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> prime(N, 1);
	prime[1] = 0;
	for (int i = 2; i * i < N; ++i) {
		if (prime[i]) {
			for (int j = i * i; j < N; j += i) prime[j] = 0;
		}
	}

	for (int i = 1; i < N; ++i) {
		if (prime[i]) {
			int l = len(i);
			if (l == 1) continue;
			else {
				int m = -1;
				for (int j = 0; j < l; ++j) {
					int now = i % ten[j] + i / ten[j + 1] * ten[j];
					m = max(m, prime[now] + 1);
				}
				prime[i] = m;
			}
		}
	}

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int a, b;
		cin >> a >> b;

		a = prime[a];
		b = prime[b];

		cout << "Case #" << test << '\n';

		if (a > b) cout << 1 << '\n';
		else if (b > a) cout << 2 << '\n';
		else cout << 3 << '\n';
	}
}