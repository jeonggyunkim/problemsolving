#include <iostream>

int n;
int map[503][503];
int day[503][503] = {0};

int ver[4] = {-1, 1, 0, 0};
int hor[4] = {0, 0, 1, -1};

int cal(int i, int j) {
	if (day[i][j] > 0) return day[i][j];
	int max = 1, t;
	for (int k = 0; k < 4; ++k) {
		if (i + ver[k] < 0 || j + hor[k] < 0 || i + ver[k] >= n || j + hor[k] >= n) continue;
		if (map[i + ver[k]][j + hor[k]] > map[i][j]) {
			t = cal(i + ver[k], j + hor[k]) + 1;
			if (t > max) max = t;
		}
	}
	return day[i][j] = max;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &map[i][j]);
	int max = -1, t;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		t = cal(i, j);
		if (max < t) max = t;
	}
	printf("%d\n", max);
}