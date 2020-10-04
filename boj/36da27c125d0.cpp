#include <iostream>
using namespace std;

int arr[1010];

int change(int start, int end) {
	int ret = 100;
	for (int i = start; i <= end; ++i) ret = min(ret, arr[i]);

	for (int i = start; i <= end; ++i) arr[i] -= ret;

	int ind = -1;
	for (int i = start; i <= end; ++i) {
		if (arr[i]) {
			if (ind == -1) ind = i;
		}
		else {
			if (ind != -1) {
				ret += change(ind, i - 1);
				ind = -1;
			}
		}
	}
	if (ind != -1) ret += change(ind, end);

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < n; ++i) {
		cin >> t;
		arr[i] -= t;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i]) {
			for (int j = i; j <= n; ++j) {
				if (j == n || !arr[j] || (arr[j] > 0) != (arr[i] > 0)) {
					if (arr[i] < 0) {
						for (int k = i; k < j; ++k) arr[k] = -arr[k];
					}
					ans += change(i, j - 1);
					i = j - 1;
					break;
				}
			}
		}
	}
	cout << ans;
}