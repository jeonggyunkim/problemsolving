#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int ans[8];
int used[8];

void rec(int d) {
	if (d == m) {
		for (int i = 0; i < m; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			int prt = 1;
			for (int j = 0; j < i; ++j) {
				if (!used[j] && arr[i] == arr[j]) prt = 0;
			}
			if (prt) {
				used[i] = 1;
				ans[d] = arr[i];
				rec(d + 1);
				used[i] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	rec(0);
}