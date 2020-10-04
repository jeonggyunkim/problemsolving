#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	int tile[101] = {0, 1, 2};
	for (int i = 3; i <= 100; ++i) tile[i] = (tile[i - 1] + tile[i - 2]) % MOD;
	tile[0] = 1;


	while (tc--) {
		int n, t;
		cin >> n;

		if (n & 1) t = tile[n] - tile[n / 2];
		else t = tile[n] - tile[n / 2] - tile[n / 2 - 1];
		while (t < 0) t += MOD;
		cout << t << '\n';
	}
}
