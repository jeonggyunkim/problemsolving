#include <iostream>
#include <memory.h>

int map[501][501];
int num[501][501];
int m, n;

int cal(int i, int j) {
	if (num[i][j] != -1) return num[i][j];
	int t = 0;
	if (i > 0 && map[i][j] > map[i - 1][j]) t += cal(i - 1, j);
	if (i < m - 1 && map[i][j] > map[i + 1][j]) t += cal(i + 1, j);
	if (j > 0 && map[i][j] > map[i][j - 1]) t += cal(i, j - 1);
	if (j < n - 1 && map[i][j] > map[i][j + 1]) t += cal(i, j + 1);
	return num[i][j] = t;
}


int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) scanf("%d", &map[i][j]);
	memset(num, -1, sizeof(num));
	num[m - 1][n - 1] = 1;

	int r = cal(0, 0);
	printf("%d\n", r);
}