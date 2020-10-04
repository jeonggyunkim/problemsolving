#include <vector>
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int m = key.size(), n = lock.size();
	int keyr[4][20][20];
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			keyr[0][i][j] = key[i][j];
		}
	}
	for (int r = 1; r < 4; ++r) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
				keyr[r][i][j] = keyr[r - 1][m - 1 - j][i];
			}
		}
	}
	int hom = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (lock[i][j] == 0) hom++;
		}
	}

	for (int i = -m + 1; i < n; ++i) {
		for (int j = -m + 1; j < n; ++j) {
			int nowhom = 0;
			for (int ii = 0; ii < m; ++ii) {
				if (i + ii < 0 || i + ii >= n) continue;
				for (int jj = 0; jj < m; ++jj) {
					if (j + jj < 0 || j + jj >= n) continue;
					if (lock[i + ii][j + jj] == 0) nowhom++;
				}
			}
			if (nowhom != hom) continue;
			for (int r = 0; r < 4; ++r) {
				for (int ii = 0; ii < m; ++ii) {
					if (i + ii < 0 || i + ii >= n) continue;
					for (int jj = 0; jj < m; ++jj) {
						if (j + jj < 0 || j + jj >= n) continue;
						if (keyr[r][ii][jj] + lock[i + ii][j + jj] != 1) {
							goto next;
						}
					}
				}
				return 1;
				next:;
			}
		}
	}
	return 0;
}
