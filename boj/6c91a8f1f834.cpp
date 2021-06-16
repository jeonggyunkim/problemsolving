#include <iostream>
#include <algorithm>
using namespace std;

int arr[50];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);

	int ans = min(2, n);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (arr[i] + arr[j] > arr[k]) {
					ans = max(ans, k - j + 2);
				}
			}
		}
	}
	cout << ans;
}