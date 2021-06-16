#include <iostream>
#include <algorithm>
using namespace std;

long long arr[5000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long ans = (1LL << 60), a, b, c;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; ++i) {
		int k = n - 1;
		for (int j = i + 1; j < n; ++j) {
			while (k > j) {
				long long now = abs(arr[i] + arr[j] + arr[k]);
				if (now < ans) {
					ans = now;
					a = arr[i];
					b = arr[j];
					c = arr[k];
				}
				long long low = abs(arr[i] + arr[j] + arr[k - 1]);
				if (low <= now) k--;
				else break;
			}
			if (k <= j) break;
		}
	}
	cout << a << ' ' << b << ' ' << c;
}