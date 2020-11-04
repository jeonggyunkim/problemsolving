#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int c, v, l;
		cin >> c >> v >> l;

		long long con = 0, vow = v, t;
		for (int i = 1; i < l; ++i) {
			t = ((con + vow) * v) % MOD;
			con = (vow * c) % MOD;
			vow = t;
		}
		cout << "Case #" << test << ": " << (con + vow) % MOD << '\n';
	}
}