#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> arr(n), bill(m);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < m; ++i) cin >> bill[i];

	int i = 0, j = 0;
	int ans = 0;
	while (i < n && j < m) {
		if (arr[i] <= bill[j]) {
			ans++;
			i++;
			j++;
		}
		else i++;
	}
	cout << ans;
}