#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, t;
	cin >> n >> k;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int ans = 0;
	int i = 0;
	while (i < n && arr[i] <= k) {
		ans++;
		i++;
	}
	if (ans == n) {
		cout << n;
		return 0;
	}
	i = n - 1;
	while (i >= 0 && arr[i] <= k) {
		ans++;
		i--;
	}
	cout << ans;
}