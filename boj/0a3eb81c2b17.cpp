#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i].second >> arr[i].first;
	sort(arr.begin(), arr.end());

	int now = 1 << 30;
	for (int i = n - 1; i >= 0; --i) {
		if (now > arr[i].first) now = arr[i].first;
		now -= arr[i].second;
	}
	if (now < 0) cout << -1;
	else cout << now;
}