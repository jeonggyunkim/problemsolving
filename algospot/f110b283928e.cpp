#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		int arr[101];
		for (int i = 0; i < n; ++i) cin >> arr[i];

		int t = 0;
		for (int i = 0; i < n - 1; ++i) {
			sort(arr, arr + n - i, greater<int>());
			arr[n - i - 2] += arr[n - i - 1];
			t += arr[n - i - 2];
		}

		cout << t << '\n';
	}
}
