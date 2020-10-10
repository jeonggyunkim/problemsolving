#include <iostream>
using namespace std;

int arr[500][500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> arr[i][j];
			}
		}

		int ans = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				if (arr[i - 1][j - 1] + arr[i][j] > arr[i - 1][j] + arr[i][j - 1]) ans = 0;
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}