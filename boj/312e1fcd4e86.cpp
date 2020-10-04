#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

const ll A = 982384651;
const ll B = 1032384667;

int h[1000010];
int p[1000010];

int strhash(int a, int b) {
	int ret = h[b + 1] - ((ll)h[a] * p[b - a + 1]) % B;
	if (ret < 0) ret += B;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	for (int i = 1; i <= n; ++i) {
		h[i] = ((h[i - 1] * A) + s[i - 1]) % B;
	}

	p[0] = 1;
	for (int i = 1; i <= n; ++i) p[i] = (p[i - 1] * A) % B;

	for (int len = 1; ; ++len) {
		bool imp = 0;
		int v = strhash(0, len - 1);
		for (int i = len; i <= n - len; i += len) {
			int now = strhash(i, i + len - 1);
			if (v != now) {
				imp = 1;
				break;
			}
		}
		if (!imp && (n % len)) {
			int t = n % len;
			if (strhash(0, t - 1) != strhash(n - t, n - 1)) imp = 1;
		}
		if (!imp) {
			cout << len;
			return 0;
		}
	}
}