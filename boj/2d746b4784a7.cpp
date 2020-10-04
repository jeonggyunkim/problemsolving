#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	int y1, y2;
	cin >> y1 >> y2;

	vector<int> arr1(m), arr2(n);
	for (int i = 0; i < m; ++i) cin >> arr1[i];
	for (int i = 0; i < n; ++i) cin >> arr2[i];

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	int low = 987654321, cnt = 0;
	for (int i = 0; i < m; ++i) {
		auto it = lower_bound(arr2.begin(), arr2.end(), arr1[i]);
		if (it != arr2.end()) {
			int d = *it - arr1[i];
			if (d < low) {
				low = d;
				cnt = 1;
			}
			else if (d == low) {
				cnt++;
			}
		}

		if (it != arr2.begin()) {
			it--;
			int d = arr1[i] - *it;
			if (d < low) {
				low = d;
				cnt = 1;
			}
			else if (d == low) {
				cnt++;
			}
		}
	}
	cout << abs(y1 - y2) + low << ' ' << cnt;
}