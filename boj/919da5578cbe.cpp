#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int arr[201][201];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cin >> arr[i][j];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			bool ans = 1;
			for (int k = 0; k < n; ++k) {
				if (i == k || j == k) continue;
				if (arr[i][k] + arr[k][j] == arr[i][j]) {
					ans = 0;
					break;
				}
			}
			if (ans) cout << i + 1 << ' ' << j + 1 << '\n';
		}
	}
}