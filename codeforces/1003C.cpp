#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int sum[5010] = {};
	for (int i = 1; i <= n; ++i) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}

	double ans = -1;
	for (int p = k; p <= n; ++p) {
		for (int st = 1; st <= n - p + 1; ++st) {
			double t = sum[st + p - 1] - sum[st - 1];
			t /= p;
			ans = max(ans, t);
		}
	}
	cout.precision(20);
	cout << ans << '\n';
}