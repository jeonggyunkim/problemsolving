#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<long long> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int j = 0;
	long long ans = 1LL << 40;
	for (int i = 0; i < n; ++i) {
		while (j < n && arr[j] < arr[i] + m) j++;
		if (j != n) ans = min(ans, arr[j] - arr[i]);
	}
	cout << ans;
}