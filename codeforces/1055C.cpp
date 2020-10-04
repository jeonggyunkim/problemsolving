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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l1, r1, t1;
	int l2, r2, t2;

	cin >> l1 >> r1 >> t1;
	cin >> l2 >> r2 >> t2;

	if (l1 < l2) {
		swap(l1, l2);
		swap(r1, r2);
		swap(t1, t2);
	}
	r1 -= l2; l1 -= l2;
	r2 -= l2; l2 -= l2;

	int g = gcd(t1, t2);

	int low = l1 / g;
	int ans1 = min(low * g + r2, r1) - max(low * g, l1) + 1;
	low++;
	int ans2 = min(low * g + r2, r1) - max(low * g, l1) + 1;

	cout << max({ans1, ans2, 0});
}