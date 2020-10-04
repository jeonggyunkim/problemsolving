#include <iostream>
#include <vector>
#define N 10010
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<bool> prime(N, 1);
	for (int i = 2; i * i < N; ++i) {
		if (prime[i]) {
			for (int j = i * i; j < N; j += i) prime[j] = 0;
		}
	}

	int t;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		int a = t / 2;
		int b = t - a;

		while (!prime[a] || !prime[b]) {
			a--; b++;
		}
		cout << a << ' ' << b << '\n';
	}
}