#include <iostream>
#define N 1000010
using namespace std;

typedef long long ll;

const ll A = 999999937;
const ll B = 1e9 + 7;

int s[N];
int p[N];
int h[N];

int strHash(int i, int j) {
	ll ret = h[j + 1] - ((ll)h[i] * p[j - i + 1]) % B;
	if (ret < 0) ret += B;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> s[i];

	for (int i = 1; i <= n; ++i) {
		h[i] = (h[i - 1] * A + s[i - 1]) % B;
	}

	p[0] = 1;
	for (int i = 1; i <= N; ++i) {
		p[i] = (p[i - 1] * A) % B;
	}

	int ans = n;
	int i = n - 2;
	while (i >= 0) {
		if (s[i] == s[i + 1]) ans--;
		else break;
		i--;
	}

	int ansk = ans - 1, ansp = 1;

	for (int len = 2; len < n; ++len) {
		if (len > ans) break;
		int hashed = strHash(n - len, n - 1);
		int cum = len;
		int start = n - len - len;
		while (start >= 0) {
			if (strHash(start, start + len - 1) != hashed) break;
			cum += len;
			start -= len;
		}
		int same = n - cum;
		int dest = ans - len - 1;

		if (same - len >= dest) continue;
		else if (same <= dest) {
			ans = same + len;
			ansp = len;
			ansk = same;
			int j = same - 1;
			while (j >= 0 && s[j] == s[j + len]) {
				ans--;
				ansp = len;
				ansk = j;
				j--;
			}
		}
		else {
			if (strHash(dest, same - 1) != strHash(dest + len, same - 1 + len)) continue;
			ans = dest + len;
			ansp = len;
			ansk = dest;
			int j = dest - 1;
			while (j >= 0 && s[j] == s[j + len]) {
				ans--;
				ansp = len;
				ansk = j;
				j--;
			}
		}
	}
	cout << ansk << ' ' << ansp;
}
