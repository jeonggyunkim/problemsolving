#include <iostream>
#include <memory.h>

int main() {
	int tc, n;
	scanf("%d", &tc);

	int board[100][100];
	bool status[100][100];
	while (tc--) {
		scanf("%d", &n);
		memset(status, 0, sizeof(status));
		for (int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) scanf("%d", &board[i][j]);

		status[0][0] = 1;
		for (int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
			if (status[i][j]) {
				if (i + board[i][j] < n) status[i + board[i][j]][j] = 1;
				if (j + board[i][j] < n) status[i][j + board[i][j]] = 1;
			}
		}
		if (status[n - 1][n - 1]) printf("YES\n");
		else printf("NO\n");
	}
}
