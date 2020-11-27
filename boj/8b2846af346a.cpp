#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, k;
		cin >> n >> k;

		vector<int> arr(n);
		for (int i = 0; i < n; ++i) cin >> arr[i];
		sort(arr.begin(), arr.end());

		int ptr = n - 1;
		int small = INF;
		int cnt = 0, t;
		for (int i = 0; i < n; ++i) {
			while (ptr > 0 && abs(arr[ptr - 1] + arr[i] - k) < abs(arr[ptr] + arr[i] - k)) ptr--;
			if (ptr != 0 && ptr - 1 != i) {
				t = abs(arr[ptr - 1] + arr[i] - k);
				if (t < small) {
					small = t;
					cnt = 1;
				}
				else if (t == small) cnt++;
			}
			if (ptr != i) {
				t = abs(arr[ptr] + arr[i] - k);
				if (t < small) {
					small = t;
					cnt = 1;
				}
				else if (t == small) cnt++;
			}
			if (ptr != n - 1 && ptr + 1 != i) {
				t = abs(arr[ptr + 1] + arr[i] - k);
				if (t < small) {
					small = t;
					cnt = 1;
				}
				else if (t == small) cnt++;
			}
		}
		cout << cnt / 2 << '\n';
	}
}