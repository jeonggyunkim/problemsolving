#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int l, r, n;
		cin >> l >> r >> n;

		vector<double> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		
		double ans = 0;
		int cnt = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (cnt < l) {
				ans += arr[i];
				cnt++;
			}
			else if (cnt >= r) {
				ans += 1 - arr[i];
			}
			else {
				if (arr[i] >= 0.5) {
					ans += arr[i];
					cnt++;
				}
				else {
					ans += 1 - arr[i];
				}
			}
		}
		cout << "Data Set " << test << ":\n";
		cout.precision(2);
		cout << fixed;
		cout << ans << '\n';
	}
}