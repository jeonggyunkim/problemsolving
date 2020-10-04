#include <iostream>

int dir1[4] = {-1, 0, 1, 0};
int dir2[4] = {0, 1, 0, -1};

int main() {
	int n, m;
	int map[51][51];
	scanf("%d %d", &n, &m);

	int i, j, d;
	scanf("%d %d %d", &i, &j, &d);

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", &map[i][j]);

	while (true) {
		map[i][j] = 2;
		int dd = (d + 3) % 4;
		bool brk = false;
		for (int rep = 0; rep < 4; ++rep) {
			if (i + dir1[dd] < 0 || i + dir1[dd] >= n || j + dir2[dd] < 0 || j + dir2[dd] >= m || map[i + dir1[dd]][j + dir2[dd]] != 0) dd = (dd + 3) % 4;
			else {
				d = dd;
				brk = true;
				break;
			}
		}
		if (brk) {
			i += dir1[d];
			j += dir2[d];
		}
		else {
			int dd = (d + 2) % 4;
			if (i + dir1[dd] < 0 || i + dir1[dd] >= n || j + dir2[dd] < 0 || j + dir2[dd] >= m || map[i + dir1[dd]][j + dir2[dd]] == 1) {
				break;
			}
			i += dir1[dd];
			j += dir2[dd];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (map[i][j] == 2) cnt++;
	}

	printf("%d\n", cnt);
}