#include <iostream>
using namespace std;

int arr[10][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K, n;
	cin >> K >> n;

	int t;
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> t;
			t--;
			arr[i][t] = j;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			bool con = 1;
			for (int k = 0; k < K; ++k) {
				if (arr[k][i] >= arr[k][j]) con = 0;
			}
			if (con) ans++;
		}
	}
	cout << ans;
}
