#include <iostream>
using namespace std;

int n, m;
char arr[3][4];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int st[10][2];
bool vis[3][3];

bool dfs(int i, int j, int d, int value, bool plus) {
	st[d][0] = i;
	st[d][1] = j;
	vis[i][j] = 1;
	if ((i + j) % 2 == 0) {
		if (plus) value += arr[i][j] - '0';
		else value -= arr[i][j] - '0';

		if (d == 2 * m - 1) {
			if (value == n) {
				cout << "1\n";
				for (int i = 1; i <= d; ++i) {
					cout << st[i][0] << ' ' << st[i][1] << '\n';
				}
				return 1;
			}
			else {
				vis[i][j] = 0;
				return 0;
			}
		}
	}
	else {
		if (arr[i][j] == '+') plus = 1;
		else plus = 0;
	}
	for (int k = 0; k < 4; ++k) {
		int ii = i + loc[k][0];
		int jj = j + loc[k][1];
		if (ii < 0 || ii > 2 || jj < 0 || jj > 2 || vis[ii][jj]) continue;
		if (dfs(ii, jj, d + 1, value, plus)) return 1;
	}
	vis[i][j] = 0;
	return 0;
}

int main() {
	cin >> n >> m;
	cin >> arr[0] >> arr[1] >> arr[2];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if ((i + j) % 2 == 0) {
				if (dfs(i, j, 1, 0, 1)) return 0;
			}
		}
	}
	cout << 0;
}