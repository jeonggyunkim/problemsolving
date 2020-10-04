#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long> arr(n);
	vector<int> two(n, 0);
	int cnt[100] = {};

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		two[i] = __builtin_ctzll(arr[i]);
		cnt[two[i]]++;
	}

	int large = -1, maxi;
	for (int i = 0; i < 100; ++i) {
		if (cnt[i] > large) {
			large = cnt[i];
			maxi = i;
		}
	}

	cout << n - large << '\n';
	for (int i = 0; i < n; ++i) {
		if (two[i] != maxi) {
			cout << arr[i] << ' ';
		}
	}
}
