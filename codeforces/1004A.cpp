#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, d;
	cin >> n >> d;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int ans = 0;
	for (int i = 1; i < n; ++i) {
		if (arr[i] - arr[i - 1] == 2 * d) ans++;
		else if (arr[i] - arr[i - 1] > 2 * d) ans += 2;
	}
	ans += 2;

	cout << ans;
}