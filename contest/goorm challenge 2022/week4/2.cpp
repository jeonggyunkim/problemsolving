#include <iostream>
#include <memory.h>
using namespace std;

int arr[40][40], arr2[40][40];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt = 0, ans = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j]) cnt++;
		}
	}

	while (cnt) {
		memcpy(arr2, arr, sizeof(arr));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (arr2[i][j] == 0) {
					for (int k = 0; k < 4; ++k) {
						int x = i + loc[k][0];
						int y = j + loc[k][1];
						if (x < 0 || x >= n || y < 0 || y >= n) continue;
						if (arr[x][y]) {
							arr[x][y]--;
							if (arr[x][y] == 0) cnt--;
						}
					}
				}
			}
		}
		ans++;
	}
	cout << ans;
}