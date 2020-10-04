#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s, t;
	int sum[100001] = {};
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		sum[i] = sum[i - 1] + t;
	}

	int ans = 1 << 30;
	for (int i = 1; i <= n; ++i) {
		int low = i, high = n, mid;
		if (sum[low] - sum[i - 1] >= s) {
			cout << 1;
			return 0;
		}
		if (sum[high] - sum[i - 1] < s) break;
		while (high - low > 1) {
			mid = (low + high) / 2;
			if (sum[mid] - sum[i - 1] >= s) high = mid;
			else low = mid;
		}
		ans = min(ans, high - i + 1);
	}
	if (ans == (1 << 30)) cout << 0;
	else cout << ans;
}