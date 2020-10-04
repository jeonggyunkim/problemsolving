#include <iostream>
#define MOD 31991
using namespace std;

int n;
int m[51][51], ans[51][51];

void power() {
	int t[51][51] = {};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				t[i][j] += m[i][k] * m[k][j];
				t[i][j] %= MOD;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			m[i][j] = t[i][j];
		}
	}
}

void prod() {
	int t[51][51] = {};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				t[i][j] += ans[i][k] * m[k][j];
				t[i][j] %= MOD;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans[i][j] = t[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> n >> t;

	for (int i = 0; i < n; ++i) {
		ans[i][i] = 1;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 || i == j + 1) m[i][j] = 1;
		}
	}

	for (long long i = 1; i < (1LL << 35); i <<= 1) {
		if (t & i) prod();
		power();
	}

	cout << ans[0][0];
}