#include <iostream>
#include <vector>
#define N (123456 * 2 + 1)
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<bool> prime(N, 1);
	prime[0] = prime[1] = 0;

	for (int i = 2; i * i < N; ++i) {
		if (prime[i]) {
			for (int j = i * i; j < N; j += i) {
				prime[j] = 0;
			}
		}
	}
	vector<int> sum(N, 0);
	for (int i = 1; i < N; ++i) {
		sum[i] = sum[i - 1] + prime[i];
	}

	int n;
	while (cin >> n, n) {
		cout << sum[2 * n] - sum[n] << '\n';
	}
}