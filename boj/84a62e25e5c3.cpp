#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long SQ(__int128_t t) {
	__int128_t low = 0, high = sqrt(t) + 10;
	while (high - low != 1) {
		__int128_t mid = (low + high) / 2;
		if (mid * mid <= t) low = mid;
		else high = mid;
	}
	if (low * low == t) return low;
	else return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout.precision(10);
	cout << fixed;

	int tc;
	cin >> tc;

	while (tc--) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;

		__int128_t ans;
		if (d == 0) {
			ans = 0;
		}
		else {
			__int128_t dd = abs(d);
			for (long long i = 1; i * i <= dd; ++i) {
				if (d % i == 0) {
					__int128_t j = i;
					if (a * j * j * j + b * j * j + c * j + d == 0) {
						ans = j;
						break;
					}
					j = -i;
					if (a * j * j * j + b * j * j + c * j + d == 0) {
						ans = j;
						break;
					}
					j = dd / i;
					if (a * j * j * j + b * j * j + c * j + d == 0) {
						ans = j;
						break;
					}
					j = -dd / i;
					if (a * j * j * j + b * j * j + c * j + d == 0) {
						ans = j;
						break;
					}
				}
			}
		}

		__int128_t aa, bb, cc;
		aa = a;
		bb = a * ans + b;
		cc = a * ans * ans + b * ans + c;

		__int128_t D = bb * bb - 4 * aa * cc;
		if (D > 0) {
			double anss[3];
			anss[0] = ans;
			if (SQ(D) != -1) {
				int cnt = 1;
				__int128_t up, down;
				down = 2 * aa;
				up = -bb + SQ(D);
				if (up % down != 0 || up / down != ans) anss[cnt++] = (double)up / down;
				up = -bb - SQ(D);
				if (up % down != 0 || up / down != ans) anss[cnt++] = (double)up / down;
				sort(anss, anss + cnt);
				for (int i = 0; i < cnt; ++i) cout << anss[i] << ' ';
				cout << '\n';
			}
			else {
				anss[1] = (-bb + sqrt(D)) / (2 * aa);
				anss[2] = (-bb - sqrt(D)) / (2 * aa);
				sort(anss, anss + 3);
				for (int i = 0; i < 3; ++i) cout << anss[i] << ' ';
				cout << '\n';
			}
		}
		else if (D == 0) {
			if (-bb % (2 * aa) == 0 && -bb / (2 * aa) == ans) cout << (double)ans << '\n';
			else {
				double ans2 = -bb / (2.0 * aa);
				cout << min((double)ans, ans2) << ' ' << max((double)ans, ans2) << '\n';
			}
		}
		else {
			cout << (double)ans << '\n';
		}
	}
}