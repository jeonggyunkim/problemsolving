#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t) arr.push_back(i);
	}

	int ans = arr.back() + 1, l = ans, r = 0, first = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (i) {
			int now = 2 * (arr[i - 1] + 1) + n - arr[i];
			if (now < ans) {
				ans = now;
				l = arr[i - 1] + 1;
				r = arr[i - 1] + 1 + n - arr[i];
				first = 0;
			}
		}
		if (i != n - 1) {
			int now = arr[i - 1] + 1 + 2 * (n - arr[i]);
			if (now < ans) {
				ans = now;
				l = arr[i - 1] + 1 + n - arr[i];
				r = n - arr[i];
				first = 1;
			}
		}
	}
	if (n - arr[0] < ans) {
		ans = n - arr[0];
		l = 0;
		r = n - arr[0];
	}
	cout << ans << '\n';
	if (first) {
		for (int i = 0; i < r; ++i) cout << 'R';
		for (int i = 0; i < l; ++i) cout << 'L';
	}
	else {
		for (int i = 0; i < l; ++i) cout << 'L';
		for (int i = 0; i < r; ++i) cout << 'R';
	}
}