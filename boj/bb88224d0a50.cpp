#include <iostream>
#include <string>
using namespace std;

int dp[2501] = {};
bool pal[2501][2501] = {};
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		int l = i, r = i;
		while (l >= 0 && r < s.size()) {
			if (s[l] == s[r]) pal[l][r] = 1;
			else break;
			l--; r++;
		}
		l = i, r = i + 1;
		while (l >= 0 && r < s.size()) {
			if (s[l] == s[r]) pal[l][r] = 1;
			else break;
			l--; r++;
		}
	}

	for (int i = s.size() - 1; i >= 0; --i) {
		int t, min = 25000;
		for (int j = i; j < s.size(); ++j) {
			if (pal[i][j]) {
				t = dp[j + 1] + 1;
				if (t < min) min = t;
			}
		}
		dp[i] = min;
	}

	cout << dp[0];
}