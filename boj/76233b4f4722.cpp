#include <iostream>
#include <set>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	long long fac[13];
	fac[1] = 1;
	for (int i = 2; i <= 12; ++i) {
		fac[i] = fac[i - 1] * i;
	}

	while (tc--) {
		int n;
		string s;
		cin >> n >> s;

		if (n <= 12) {
			string ans = to_string(fac[n]);
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] >= 'a') cout << ans[i] << ' ';
			}
			cout << '\n';
			continue;
		}

		int sum = 0;
		for (char u: s) {
			if (u < 'a') sum += u - '0';
		}

		set<ii> cand;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if ((i + j + sum) % 9 == 0) {
					cand.insert({i, j});
				}
			}
		}

		for (ii ans: cand) {
			int mod = 0;
			for (char u: s) {
				mod *= 10;
				if (u == 'a') mod += ans.first;
				else if (u == 'b') mod += ans.second;
				else mod += u - '0';
				mod %= 13;
			}
			if (mod == 0) cout << ans.first << ' ' << ans.second << '\n';
		}
	}
}