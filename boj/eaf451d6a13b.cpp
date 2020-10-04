#include <iostream>
#define MOD 1000000000
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int base[10][1 << 10] = {};
	for (int i = 1; i < 10; ++i) {
		base[i][1 << i] = 1;
	}

	int n;
	cin >> n;

	for (int rep = 1; rep < n; ++rep) {
		int temp[10][1 << 10] = {};
		for (int i = 0; i < 10; ++i) for (int j = 0; j < (1 << 10); ++j) {
			if (base[i][j] == 0) continue;
			if (i != 0) {
				temp[i - 1][j | (1 << (i - 1))] += base[i][j];
				temp[i - 1][j | (1 << (i - 1))] %= MOD;
			}
			if (i != 9) {
				temp[i + 1][j | (1 << (i + 1))] += base[i][j];
				temp[i + 1][j | (1 << (i + 1))] %= MOD;
			}
		}
		for (int i = 0; i < 10; ++i) for (int j = 0; j < (1 << 10); ++j) base[i][j] = temp[i][j];
	}

	int ans = 0;
	for (int i = 0; i < 10; ++i) ans = (ans + base[i][(1 << 10) - 1]) % MOD;
	cout << ans;
}