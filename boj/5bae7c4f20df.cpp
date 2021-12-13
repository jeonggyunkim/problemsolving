#include <iostream>
using namespace std;

char arr[50][51];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	int mx = -1;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (arr[i][j] == 'Y') cnt++;
			else {
				for (int k = 0; k < n; ++k) {
					if (arr[i][k] == 'Y' && arr[k][j] == 'Y') {
						cnt++;
						break;
					}
				}
			}
		}
		mx = max(mx, cnt);
	}
	cout << mx;
}