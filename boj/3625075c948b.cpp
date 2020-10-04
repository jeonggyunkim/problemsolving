#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c, t;
	cin >> r >> c >> t;

	int air[51][51] = {};

	int pos1 = -1, pos2 = -1;
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		cin >> air[i][j];
		if (air[i][j] == -1) {
			if (pos1 == -1) pos1 = i;
			else pos2 = i;
		}
	}

	for (int rep = 0; rep < t; ++rep) {
		int temp[51][51] = {};
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
			if (air[i][j] == -1) {
				temp[i][j] = -1;
				continue;
			}
			int pol = air[i][j] / 5;
			if (i != 0 && air[i - 1][j] != -1) {
				temp[i - 1][j] += pol;
				air[i][j] -= pol;
			}
			if (i != r - 1 && air[i + 1][j] != -1) {
				temp[i + 1][j] += pol;
				air[i][j] -= pol;
			}
			if (j != 0 && air[i][j - 1] != -1) {
				temp[i][j - 1] += pol;
				air[i][j] -= pol;
			}
			if (j != c - 1 && air[i][j + 1] != -1) {
				temp[i][j + 1] += pol;
				air[i][j] -= pol;
			}
			temp[i][j] += air[i][j];
		}

		int tt1 = 0, tt2 = 0;
		for (int i = pos1 - 1; i >= 1; --i) temp[i][0] = temp[i - 1][0];
		for (int i = pos2 + 1; i < r - 1; ++i) temp[i][0] = temp[i + 1][0];

		for (int i = 0; i < c - 1; ++i) {
			temp[0][i] = temp[0][i + 1];
			temp[r - 1][i] = temp[r - 1][i + 1];
		}

		for (int i = 0; i < pos1; ++i) temp[i][c - 1] = temp[i + 1][c - 1];
		for (int i = r - 1; i > pos2; --i) temp[i][c - 1] = temp[i - 1][c - 1];

		for (int i = c - 1; i >= 2; --i) {
			temp[pos1][i] = temp[pos1][i - 1];
			temp[pos2][i] = temp[pos2][i - 1];
		}

		temp[pos1][1] = 0;
		temp[pos2][1] = 0;

		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) air[i][j] = temp[i][j];
	}

	int ans = 0;
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		if (air[i][j] != -1) ans += air[i][j];
	}

	cout << ans;
}