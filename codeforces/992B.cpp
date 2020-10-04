#include <bits/stdc++.h>
using namespace std;

vector<int> div(int n) {
	vector<int> ret;
	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			ret.push_back(1);
			while (n % i == 0) {
				n /= i;
				ret.back() = ret.back() * i;
			}
		}
		i++;
	}
	if (n != 1) ret.push_back(n);
	return ret;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l, r, x, y;
	cin >> l >> r >> x >> y;

	if (y % x != 0) {
		cout << 0;
		return 0;
	}

	int ans = 0;
	vector<int> d = div(y / x);

	int tt = 1 << d.size();
	for (int i = 0; i < tt; ++i) {
		int a = x, b = x;
		for (int j = 0; j < d.size(); ++j) {
			if ((1 << j) & i) a *= d[j];
			else b *= d[j];
		}
		if (a >= l && a <= r && b >= l && b <= r) ans++;
	}

	cout << ans;
}