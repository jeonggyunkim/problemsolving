#include <iostream>
using namespace std;

int arr[101];

int main() {
	int n, k, b;
	cin >> n >> k >> b;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	b--;
	b %= n;

	int ans = 0;
	while (k--) {
		ans += arr[b];
		b = (b + 1) % n;
	}
	cout << ans;
}