#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long len[2501] = {1, 1};

	long long r;
	for (int i = 2; i <= 2500; ++i) {
		for (int j = 0; j < i; ++j) {
			r = (len[j] * len[i - 1 - j]) % MOD;
			len[i] = (len[i] + r) % MOD;
		}
	}

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		if (n & 1) cout << 0 << '\n';
		else {
			cout << len[n >> 1] << '\n';
		}
	}
}