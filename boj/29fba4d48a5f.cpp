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

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += arr[i];
		if (sum < i * (i + 1) / 2) {
			cout << -1;
			return 0;
		}
	}
	if (sum == n * (n - 1) / 2)	cout << 1;
	else cout << -1;
}