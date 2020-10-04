#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int ans[8];

void rec(int d, int s) {
	if (d == m) {
		for (int i = 0; i < m; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = s; i < n; ++i) {
		if (i == s || arr[i] != arr[i - 1]) {
			ans[d] = arr[i];
			rec(d + 1, i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	rec(0, 0);
}