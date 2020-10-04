#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	if (l == 1) {
		for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
		return 0;
	}

	int ans = arr[0], i;
	cout << ans << ' ';
	for (i = 1; i < l; ++i) {
		ans = min(ans, arr[i]);
		cout << ans << ' ';
	}
	while (i != n) {
		int size = min(l, n - i);
		vector<int> window(l + size - 1);
		window[l - 2] = arr[i - 1];
		for (int j = 3; j <= l; ++j) {
			window[l - j] = min(window[l - j + 1], arr[i - j + 1]);
		}
		window[l - 1] = arr[i];
		for (int j = 1; j < size; ++j) {
			window[l - 1 + j] = min(window[l - 2 + j], arr[i + j]);
		}

		for (int j = 0; j < size; ++j) {
			cout << min(window[j], window[j + l - 1]) << ' ';
		}

		i += size;
	}
}