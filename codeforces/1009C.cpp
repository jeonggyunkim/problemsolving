#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, m;
	cin >> n >> m;

	long long sum = 0, prod = 0;
	long long big, small;
	big = (n - 1) * n / 2;
	if (n & 1) small = (n / 2) * (n / 2 + 1);
	else small = (n / 2) * (n / 2);

	int a, b;
	while (m--) {
		cin >> a >> b;
		sum += a;
		if (b >= 0) prod += b * big;
		else prod += b * small;
	}
	double ans = sum;
	ans += (double)prod / n;

	cout.precision(12);
	cout << ans;
}