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

		for (int i = n - 1; i > 0; --i) {
			for (int j = m - 1; j >= 0; --j) {
				arr[i][j] = arr[i][j] - arr[i - 1][j];
			}
		}

		bool pos = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				if (arr[i][j - 1] < arr[i][j]) pos = 0;
			}
		}

		if (pos) cout << "YES\n";
		else cout << "NO\n";
	}
}