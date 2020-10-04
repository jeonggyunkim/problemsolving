#include <bits/stdc++.h>
using namespace std;

long long dp[11][62][10][1 << 10];

vector<int> itos(int b, long long n) {
	vector<int> ret;
	while (n) {
		ret.push_back(n % b);
		n /= b;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

long long find(int b, long long n) {
	if (n == 0) return 0;
	vector<int> s = itos(b, n);
	long long ret = 0;
	for (int i = 1; i < s.size(); ++i) {
		for (int j = 1; j < b; ++j) ret += dp[b][i][j][0];
	}

	int x = 0;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = (i == 0 ? 1 : 0); j < (i == s.size() - 1 ? s[i] + 1 : s[i]); ++j) {
			ret += dp[b][s.size() - i][j][x];
		}
		x ^= (1 << s[i]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int b = 2; b <= 10; ++b) {
		for (int s = 0; s < b; ++s) dp[b][1][s][1 << s] = 1;
		unsigned long long t = b;
		int len = 1;
		while (t <= 1000000000000000000) {
			for (int i = 0; i < b; ++i) {
				for (int j = 0; j < (1 << b); ++j) {
					for (int k = 0; k < b; ++k) {
						dp[b][len + 1][i][j ^ (1 << k)] += dp[b][len][i][j];
					}
				}
			}
			len++;
			t *= b;
		}
	}

	int q;
	cin >> q;

	while (q--) {
		long long b, l, r;
		cin >> b >> l >> r;
		cout << find(b, r) - find(b, l - 1) << '\n';
	}
}