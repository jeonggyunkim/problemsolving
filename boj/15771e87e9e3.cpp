#include <iostream>
#include <string>
using namespace std;

int u[501][501][4];
string str[500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> str[i];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (str[i - 1][j - 1] == 'M') {
				u[i][j][0] = max(u[i][j][0], u[i - 1][j][3] + 1);
				u[i][j][0] = max(u[i][j][0], u[i][j - 1][3] + 1);
			}
			if (str[i - 1][j - 1] == 'O') {
				u[i][j][1] = max(u[i][j][1], u[i - 1][j][0]);
				u[i][j][1] = max(u[i][j][1], u[i][j - 1][0]);
			}
			if (str[i - 1][j - 1] == 'L') {
				u[i][j][2] = max(u[i][j][2], u[i - 1][j][1]);
				u[i][j][2] = max(u[i][j][2], u[i][j - 1][1]);
			}
			if (str[i - 1][j - 1] == 'A') {
				u[i][j][3] = max(u[i][j][3], u[i - 1][j][2]);
				u[i][j][3] = max(u[i][j][3], u[i][j - 1][2]);
			}
			u[i][j][3] = max(u[i][j][3], u[i - 1][j][3]);
			u[i][j][3] = max(u[i][j][3], u[i][j - 1][3]);
		}
	}
	cout << u[n][n][3];
}