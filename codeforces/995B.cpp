#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(2 * n);
	for (int i = 0; i < 2 * n; ++i) cin >> arr[i];

	int ans = 0;
	for (int i = 0; i < 2 * n; i += 2) {
		int j = i + 1;
		while (arr[j] != arr[i]) j++;
		ans += j - i - 1;
		while (j != i + 1) {
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
	cout << ans;
}