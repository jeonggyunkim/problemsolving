#include <iostream>
#include <vector>
#include <set>
#define MOD 32749
using namespace std;

typedef pair<int, int> ii;

int choose(int n, int k) {
	long long ret = 1;
	for (int i = 1; i <= n; ++i) ret *= i;
	for (int i = 1; i <= k; ++i) ret /= i;
	for (int i = 1; i <= n - k; ++i) ret /= i;
	return ret % MOD;
}

int main() {
	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int b, w, k, c;
		cin >> b >> w >> k >> c;

		set<ii> pos;
		for (int i = 0; i <= k; ++i) {
			if (i <= b && k - i <= w) {
				pos.insert({i, k - i});
			}
		}

		int pow = 1;
		int ans = 0;
		for (int i = 0; i < c; ++i) {
			set<ii> nxt;
			vector<ii> front;
			for (int j = 0; j < k - i; ++j) {
				if (j <= b && k - i - 1 - j <= w) {
					front.push_back({j, k - i - 1 - j});
				}
			}
			if (i == c - 1) {
				for (ii u: front) {
					if (pos.count({u.first + 1, u.second}) != pos.count({u.first, u.second + 1})) {
						ans += pow * choose(u.first + u.second, u.first);
						ans %= MOD;
					}
				}
			}
			else {
				for (ii u: front) {
					if (pos.count({u.first + 1, u.second}) && pos.count({u.first, u.second + 1})) {
						nxt.insert(u);
					}
				}
				pos = nxt;
				(pow *= 2) %= MOD;
			}
		}
		cout << "Case #" << test << ": " << ans << '\n';
	}
}