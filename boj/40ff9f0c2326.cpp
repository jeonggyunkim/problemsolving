#include <iostream>
using namespace std;

int move(int diff[3][3]) {
	int ret = 0, a, b, c;
	a = min(diff[0][1], diff[1][0]);
	b = min(diff[1][2], diff[2][1]);
	c = min(diff[2][0], diff[0][2]);
	ret += diff[0][1] - a + diff[0][2] - c;
	ret += diff[1][0] - a + diff[1][2] - b;
	ret += a + b + c;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int cnt[3] = {};
	for (char u: s) cnt[u - 'A']++;
	int zero = 0;
	for (int i = 0; i < 3; ++i) if (cnt[i] == 0) zero++;

	int ans = 9999999;

	if (zero == 2) {
		cout << 0;
		return 0;
	}
	else if (zero == 1) {
		int x = 0, y = cnt[s[0] - 'A'];
		int diff = 0;
		for (int i = 0; i < y; ++i) {
			if (s[i] != s[0]) diff++;
		}
		for (int i = 0; i < s.size(); ++i) {
			ans = min(ans, diff);
			if (s[x] != s[0]) diff--;
			if (s[y] != s[0]) diff++;
			x = (x + 1) % s.size();
			y = (y + 1) % s.size();
		}
		cout << ans;
		return 0;
	}

	for (char a = 'A'; a <= 'C'; ++a) {
		for (char b = 'A'; b <= 'C'; ++b) {
			if (a == b) continue;
			for (char c = 'A'; c <= 'C'; ++c) {
				if (c == a || c == b) continue;
				string t;
				for (int i = 0; i < cnt[a - 'A']; ++i) t += a;
				for (int i = 0; i < cnt[b - 'A']; ++i) t += b;
				for (int i = 0; i < cnt[c - 'A']; ++i) t += c;

				int diff[3][3] = {};
				for (int i = 0; i < s.size(); ++i) {
					if (s[i] != t[i]) diff[s[i] - 'A'][t[i] - 'A']++;
				}
				int x = 0, y = cnt[a - 'A'], z = cnt[a - 'A'] + cnt[b - 'A'];
				for (int i = 0; i < s.size(); ++i) {
					ans = min(ans, move(diff));
					diff[s[x] - 'A'][a - 'A']--;
					diff[s[x] - 'A'][c - 'A']++;
					diff[s[y] - 'A'][b - 'A']--;
					diff[s[y] - 'A'][a - 'A']++;
					diff[s[z] - 'A'][c - 'A']--;
					diff[s[z] - 'A'][b - 'A']++;
					x = (x + 1) % s.size();
					y = (y + 1) % s.size();
					z = (z + 1) % s.size();
				}
			}
		}
	}
	cout << ans;
}