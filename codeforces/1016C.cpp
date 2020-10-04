#include <bits/stdc++.h>
using namespace std;

long long arr[300000][2];
long long sum[300001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i][0];
	for (int i = 0; i < n; ++i) cin >> arr[i][1];

	for (int i = n - 1; i >= 0; --i) sum[i] = sum[i + 1] + arr[i][0] + arr[i][1];

	long long clock = 0, clockwise = 0;
	for (int i = 0; i < n; ++i) {
		clock += i * arr[i][0];
		clockwise += i * arr[i][1];
	}
	for (int i = 0; i < n; ++i) {
		clock += (n + i) * arr[n - 1 - i][1];
		clockwise += (n + i) * arr[n - 1 - i][0];
	}

	long long ans = 0, total = 0;
	for (int i = 0; i < n; ++i) {
		if (i & 1) {
			ans = max(ans, clockwise + total);
			total += arr[i][0];
		}
		else {
			ans = max(ans, clock + total);
			total += arr[i][1];
		}
		total += 2 * sum[i + 1];
		clock -= sum[i + 1];
		clock -= ((n - i) * 2 - 1) * arr[i][1];
		clockwise -= sum[i + 1];
		clockwise -= ((n - i) * 2 - 1) * arr[i][0];
	}

	cout << ans;
}