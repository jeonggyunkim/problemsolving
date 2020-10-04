#include <iostream>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	char before[50][50];
	char after[50][50];
	for (int i = 0; i < n; ++i) scanf("%s", before + i);
	for (int i = 0; i < n; ++i) scanf("%s", after + i);

	int cnt = 0;
	for (int i = 1; i < n - 1; ++i) for (int j = 1; j < m - 1; ++j) {
		if (before[i - 1][j - 1] != after[i - 1][j - 1]) {
			cnt++;
			for (int k = -1; k < 2; ++k) for (int l = -1; l < 2; ++l) {
				if (before[i + k][j + l] == '0') before[i + k][j + l] = '1';
				else before[i + k][j + l] = '0';
			}
		}
	}

	bool same = true;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (before[i][j] != after[i][j]) {
			same = false;
			break;
		}
	}
	if (same) printf("%d\n", cnt);
	else printf("-1\n");
}