#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr.begin(), arr.end());

	int t;
	cin >> t;
	t *= 2;

	int sum = 0;
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				for (int k = 0; k < j; ++k) {
					if (!(i & (1 << k)) && (arr[j] - arr[k]) <= t) sum++;
				}
			}
			else {
				for (int k = j + 1; k < n; ++k) {
					if ((i & (1 << k)) && (arr[k] - arr[j]) <= t) sum++;
				}
			}
		}
	}

	cout << (double)sum / 2 / (1 << n) << '\n';
}