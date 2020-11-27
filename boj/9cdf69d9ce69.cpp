#include <iostream>
using namespace std;

int arr[10][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cin >> arr[i][j];
	}

	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < k ; ++ii) {
			for (int j = 0; j < n; ++j) {
				for (int jj = 0; jj < k; ++jj) {
					cout << arr[i][j] << ' ';
				}
			}
			cout << '\n';
		}
	}
}