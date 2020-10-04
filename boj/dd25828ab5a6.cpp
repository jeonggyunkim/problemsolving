#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	sort(arr.begin(), arr.end());

	vector<long long> sum(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + arr[i - 1];
	}

	int l, r;
	while (q--) {
		cin >> l >> r;
		cout << sum[r] - sum[l - 1] << '\n';
	}
}