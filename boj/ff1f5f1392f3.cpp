#include <iostream>
using namespace std;

int hp[3];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> hp[i];

	int ans = 99;
	for (int a = 0; a < 8; ++a)
	for (int b = 0; b < 8; ++b)
	for (int c = 0; c < 8; ++c)
	for (int d = 0; d < 8; ++d)
	for (int e = 0; e < 8; ++e)
	for (int f = 0; f < 8; ++f) {
		int cnt[3] = {};
		cnt[0] = 9 * (a + b) + 3 * (c + e) + d + f;
		cnt[1] = 9 * (c + d) + 3 * (a + f) + b + e;
		cnt[2] = 9 * (e + f) + 3 * (b + d) + a + c;
		int pos = 1;
		for (int i = 0; i < n; ++i) if (cnt[i] < hp[i]) pos = 0;
		if (pos) ans = min(ans, a + b + c + d + e + f);
	}
	cout << ans;
}