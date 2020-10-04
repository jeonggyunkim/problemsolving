#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> t;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	if (n == 1) {
		if (arr[0] == 0) cout << 1;
		else cout << 0;
		return 0;
	}

	int cnt = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (i == 0 || arr[i] == 1) break;
		if (arr[i - 1] + 1 == arr[i]) cnt++;
		else {
			cnt = 0;
			break;
		}
	}

	if (cnt != 0) {
		bool imp = 0;
		for (int i = 0; i < n - cnt; ++i) {
			if (arr[i] != 0) {
				int put = arr[i] - cnt;
				int canput = i + 2;
				if (canput > put) {
					imp = 1;
					break;
				}
			}
		}
		if (!imp) {
			cout << n - cnt;
			return 0;
		}
	}

	int maxop = n;
	for (int i = 0; i < n; ++i) {
		if (arr[i] != 0) maxop = max(maxop, i + 2 + n - arr[i]);
	}
	cout << maxop;
}