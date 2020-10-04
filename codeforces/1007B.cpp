#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int choose(int n, int m) {
	if (n < m) return 0;
	int ret;
	if (m == 3) {
		ret = n * (n - 1) * (n - 2);
		ret /= 6;
	}
	else {
		ret = n * (n - 1);
		ret /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> div(100001, 1);
	for (int i = 2; i <= 100000; ++i) {
		for (int j = i; j <= 100000; j += i) {
			div[j]++;
		}
	}

	int n;
	cin >> n;

	int a, b, c;
	while (n--) {
		cin >> a >> b >> c;
		int ans = 0;

		int three = div[gcd(gcd(a, b), c)];
		int two[3] = { div[gcd(a, b)], div[gcd(b, c)], div[gcd(c, a)] };
		int one[3] = { div[a], div[b], div[c] };
		int only[3];
		for (int i = 0; i < 3; ++i) only[i] = one[i] - two[i] - two[(i + 2) % 3] + three;

		int sum = three;
		for (int i = 0; i < 3; ++i) sum += one[i] - two[i];

		ans += three;
		ans += three * (sum - 1);
		ans += choose(sum, 3);

		for (int i = 0; i < 3; ++i) {
			ans += (two[i] - three) * one[(i + 2) % 3];
			ans -= choose(sum - one[i], 3);
			ans += choose(only[i], 3);
			ans -= two[(i + 1) % 3] * choose(only[i], 2);
		}

		cout << ans << '\n';
	}
}