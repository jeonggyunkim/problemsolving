#include <iostream>
using namespace std;

int arr[18][18];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cin >> arr[i][j];
	}

	long long ans = -(1LL << 60);
	for (int i = 0; i < (1 << n); ++i) {
		long long minwoo = 0, jong = 0;
		for (int j = 0; j < n; ++j) {
			long long a = 0, b = 0;
			for (int k = 0; k < n; ++k) {
				if (i & (1 << k)) a += arr[k][j];
				else b += arr[k][j];
			}
			minwoo += min(a, b);
			jong += max(a, b);
		}
		ans = max(ans, minwoo);
	}
	cout << ans << '\n';
}