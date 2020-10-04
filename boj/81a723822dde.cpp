#include <iostream>
using namespace std;

const int dir[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int arr[1100][1100];
int max_sq[1100][1100][33];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 50; i < 50 + n; ++i) for (int j = 50; j < 50 + n; ++j) {
		cin >> arr[i][j];
		max_sq[i][j][1] = arr[i][j];
	}

	for (int i = 50; i < 50 + n; ++i) for (int j = 50; j < 50 + n; ++j) {
		for (int x = -1; x <= 1; ++x) for (int y = -1; y <= 1; ++y) {
			max_sq[i][j][2] = max(max_sq[i][j][2], arr[i + x][j + y]);
		}
	}

	for (int len = 3; len < 33; ++len) {
		for (int i = 50; i < 50 + n; ++i) for (int j = 50; j < 50 + n; ++j) {
			for (int k = 0; k < 4; ++k) {
				max_sq[i][j][len] = max(max_sq[i][j][len], max_sq[i + dir[k][0]][j + dir[k][1]][len - 1]);
			}
		}
	}

	for (int i = 50; i < 50 + n; ++i) {
		for (int j = 50; j < 50 + n; ++j) {
			int ans = 0;
			for (int len = 1; len < 33; ++len) {
				ans = max(ans, max_sq[i][j][len] - len * len);
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}
}