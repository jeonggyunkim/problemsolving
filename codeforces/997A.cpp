#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;

	char str[300010];
	cin >> str;
	int part = 1;

	for (int i = 1; i < n; ++i) if (str[i] != str[i - 1]) part++;

	if (part == 1) {
		if (str[0] == '0') cout << y;
		else cout << 0;
		return 0;
	}

	long long ans = min(x, y);
	if (part % 2 == 1) ans *= (part - 3) / 2;
	else ans *= (part - 2) / 2;

	if (part % 2 == 1) {
		if (str[0] == '0') ans += min(x + y, 2 * y);
		else ans += y;
	}
	else ans += y;

	cout << ans;
}