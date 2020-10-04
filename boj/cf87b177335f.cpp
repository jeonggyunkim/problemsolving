#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	sort(arr.begin(), arr.end());

	int ans = -1;
	for (int i = 0; i < n; ++i) ans = max(ans, (n - i) * arr[i]);

	cout << ans;
}