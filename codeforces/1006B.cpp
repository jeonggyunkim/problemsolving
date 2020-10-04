#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<ii> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr.begin(), arr.end());

	int ans = 0;
	vector<int> div;
	for (int i = 0; i < k; ++i) {
		ans += arr[n - 1 - i].first;
		div.push_back(arr[n - 1 - i].second);
	}
	cout << ans << '\n';

	sort(div.begin(), div.end());

	if (k == 1) {
		cout << n;
		return 0;
	}
	cout << div[0] << ' ';
	for (int i = 1; i < k - 1; ++i) {
		cout << div[i] - div[i - 1] << ' ';
	}
	cout << n - div[k - 2];
}