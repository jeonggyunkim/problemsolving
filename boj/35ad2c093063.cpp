#include <iostream>
#include <vector>
#define N 1000000
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<bool> prime(N + 1, 1);

	prime[1] = 0;
	for (int i = 2; i * i <= N; ++i) {
		if (prime[i]) {
			for (int j = i * i; j <= N; j += i) prime[j] = 0;
		}
	}

	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; ++i) {
		if (prime[i]) cout << i << '\n';
	}
}