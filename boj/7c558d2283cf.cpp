#include <iostream>

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int r, c, depth = 0, max;
char alp[20][20];
int mask = 0;

void dfs(int i, int j) {
	if (i < 0 || i >= r || j < 0 || j >= c) return;
	if (mask & (1 << alp[i][j])) return;
	depth++;
	if (depth > max) max = depth;
	mask |= (1 << alp[i][j]);
	for (int k = 0; k < 4; ++k) {
		dfs(i + dir[k][0], j + dir[k][1]);
	}
	mask &= ~(1 << alp[i][j]);
	depth--;
}

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; ++i) scanf("%s", alp + i);
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) alp[i][j] -= 'A';

	dfs(0, 0);
	printf("%d\n", max);
}