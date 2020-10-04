#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tc, arr[42];
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i) cin >> arr[i];
		sort(arr, arr + n);

		double ans = -1;
		for (int i = 0; i <= n / 2; ++i) {
			ans = max(ans, (double)(arr[i] + arr[n - 1 - i]) / 2);
		}
		printf("%.1f\n", ans);
	}
}
