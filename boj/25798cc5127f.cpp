#include <iostream>
using namespace std;

int arr[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	int ans = -1;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			for (int k = j + 1; k < n; ++k) {
				int t = arr[i] + arr[j] + arr[k];
				if (t <= m) ans = max(ans, t);
			}

	cout << ans;
}