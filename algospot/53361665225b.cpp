#include <iostream>
#include <memory.h>

int near1[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int near2[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int status[5][5];
int temp[5][5];

bool near_find(int x, int y, int n) {
	for (int i = 0; i < 8; ++i) {
		if (x + near1[i] < 0 || x + near1[i] >= 5) continue;
		if (y + near2[i] < 0 || y + near2[i] >= 5) continue;
		if (status[x + near1[i]][y + near2[i]] == n) return true;
	}
	return false;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		char board[5][5];
		for (int i = 0; i < 5; ++i) scanf("%s", board + i);

		int n, len;
		char word[12];
		scanf("%d", &n);
		for (int w = 0; w < n; ++w) {
			scanf("%s", word);
			len = -1;
			while(word[++len]);
			memset(status, -1, sizeof(status));
			for (int loc = 0; loc < len; ++loc) {
				for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) {
					if (board[i][j] == word[loc] && near_find(i, j, loc - 1)) temp[i][j] = loc;
					else temp[i][j] = status[i][j];
				}
				for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) status[i][j] = temp[i][j];
			}
			printf("%s ", word);
			bool can = false;
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 5; ++j) {
					if (status[i][j] == (len - 1)) {
						printf("YES\n");
						can = true;
						break;
					}
				}
				if (can) break;
			}
			if (!can) printf("NO\n");
		}
	}
}
