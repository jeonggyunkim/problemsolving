#include <iostream>
#include <algorithm>
using namespace std;

int arr[8];

int main() {
	int n;
	long long ans = (1LL << 62);
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);

	do {
		long long s = 0;
		for (int i = 0; i < n; ++i) {
			if (arr[i] / 10 != s % 10) {
				s *= 10;
				s += arr[i] / 10;
			}
			s *= 10;
			s += arr[i] % 10;
		}
		ans = min(ans, s);
	} while (next_permutation(arr, arr + n));
	cout << ans;
}