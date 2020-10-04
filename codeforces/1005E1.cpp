#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int s = -1;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i] == m) s = i;
	}
	if (s == -1) {
		cout << 0;
		return 0;
	}

	map<int, int> left;
	int low = 0, high = 0;
	for (int i = s; i >= 0; --i) {
		if (arr[i] < m) low++;
		else if (arr[i] > m) high++;
		left[high - low]++;
	}

	long long ans = 0;
	low = 0; high = 0;
	for (int i = s; i < n; ++i) {
		if (arr[i] < m) low++;
		else if (arr[i] > m) high++;

		int t = high - low;
		if (left.find(1 - t) != left.end()) ans += left[1 - t];
		if (left.find(-t) != left.end()) ans += left[-t];
	}
	cout << ans;
}