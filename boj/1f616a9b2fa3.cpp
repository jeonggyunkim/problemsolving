#include <iostream>
using namespace std;

int num(string& s) {
	int ret = 0;
	for (int i = 0; i < 7; ++i) {
		if (i == 3) continue;
		ret *= 10;
		ret += s[i] - '0';
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		string a, b, c, d;
		cin >> a >> b >> c >> d;

		int aa = num(a), bb = num(b), dd = num(d);
		int ans = 6;

		if (c[0] == 'B') swap(aa, bb);

		int t[4] = {aa, aa, bb, bb};
		for (int i = 0; i < 105; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (t[j] == dd) {
					ans = min(ans, i + (j >= 2 ? 1 : 0));
				}
			}
			t[0] += 20;
			t[1] -= 20;
			t[2] += 20;
			t[3] -= 20;
			for (int j = 0; j < 4; ++j) {
				if (t[j] > 146000) t[j] = 144000;
				if (t[j] < 144000) t[j] = 146000;
			}
		}
		cout << ans << '\n';
	}
}