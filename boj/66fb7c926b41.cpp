#include <iostream>
using namespace std;

int main() {
	long long s, x;
	long long ans = 1;

	cin >> s >> x;

	if (s < x) {
		cout << 0;
		return 0;
	}

	int len1 = 0, len2 = 0;
	int sum[64] = {};
	int xo[64] = {};
	bool same = s == x;
	while (s) {
		sum[len1] = s % 2;
		len1++;
		s /= 2;
	}

	while (x) {
		xo[len2] = x % 2;
		len2++;
		x /= 2;
	}

	bool olim = 0;
	for (int i = len1 - 1; i >= 0; --i) {
		if (sum[i] == 1) {
			if (xo[i] == 0) {
				olim = 1;
			}
			else {
				if (olim) {
					cout << 0;
					return 0;
				}
				ans *= 2;
				olim = 0;
			}
		}
		else {
			if (xo[i] == 0) {
				olim = 0;
			}
			else {
				if (!olim) {
					cout << 0;
					return 0;
				}
				ans *= 2;
				olim = 1;
			}
		}
	}
	if (olim) cout << 0;
	else {
		if (same) ans -= 2;
		cout << ans;
	}
}