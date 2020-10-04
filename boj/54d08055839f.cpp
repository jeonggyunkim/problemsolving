#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	sort(arr.begin(), arr.end());
	long long ans = 0, now = 0;

	for (auto it = arr.begin(); it != arr.end(); ++it) {
		ans += *it * now;
		if (now != k) now++;
	}
	cout << ans;
}