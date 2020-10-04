#include <iostream>
#include <memory.h>
using namespace std;

typedef long long ll;

const ll A = 982384651;
const ll B = 1032384667;

int h[1000010];
int p[1000010];
int ans[1000010];

int strhash(int a, int b) {
	int ret = h[b + 1] - ((ll)h[a] * p[b - a + 1]) % B;
	if (ret < 0) ret += B;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(ans, -1, sizeof(ans));

	int n;
	string s;
	cin >> s;
	n = s.size();
	
	for (int i = 1; i <= n; ++i) {
		h[i] = ((h[i - 1] * A) + s[i - 1]) % B;
	}

	p[0] = 1;
	for (int i = 1; i <= n; ++i) p[i] = (p[i - 1] * A) % B;

	for (int len = n / 2; len >= 1; --len) {
		int stand = strhash(0, len - 1);
		for (int i = len; i + len - 1 < n; i += len) {
			int now = strhash(i, i + len - 1);
			if (now == stand) {
				ans[i + len] = i / len + 1;
			}
			else break;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (ans[i] != -1) {
			cout << i << ' ' << ans[i] << '\n';
		}
	}
}