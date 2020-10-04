#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	vector<int> ans;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (i == n - 1 || arr[i + 1] == 1) {
			cnt++;
			ans.push_back(arr[i]);
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
}