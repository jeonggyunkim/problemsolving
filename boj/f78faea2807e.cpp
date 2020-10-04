#include <iostream>

int main() {
	int r, c;
	scanf("%d %d", &r, &c);

	if (r & 1) {
		for (int i = 0; i < r; ++i) {
			if (i & 1) for (int j = 1; j < c; ++j) printf("L");
			else for (int j = 1; j < c; ++j) printf("R");
			if (i != r - 1) printf("D");
		}
	}
	else if (c & 1) {
		for (int i = 0; i < c; ++i) {
			if (i & 1) for (int j = 1; j < r; ++j) printf("U");
			else for (int j = 1; j < r; ++j) printf("D");
			if (i != c - 1) printf("R");
		}
	}
	else {
		int map[1000][1000];
		int min = 10000, rr, cc;
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
			scanf("%d", &map[i][j]);
			if ((i + j) & 1) if (map[i][j] < min) {
				min = map[i][j];
				rr = i;
				cc = j;
			}
		}
		bool down = false;
		for (int i = 0; i < c / 2; ++i) {
			if (cc < 2 * i || cc > 2 * i + 1) {
				if (down) {
					printf("R");
					for (int j = 1; j < r; ++j) printf("U");
					printf("R");
					for (int j = 1; j < r; ++j) printf("D");
				}
				else {
					for (int j = 1; j < r; ++j) printf("D");
					printf("R");
					for (int j = 1; j < r; ++j) printf("U");
					printf("R");
				}
			}
			else {
				int loc = 0;
				for (int j = 0; j < r; ++j) {
					if (j != rr) {
						if (loc) printf("L");
						else printf("R");
						loc = 1 - loc;
					}
					if (j != r - 1) printf("D");
				}
				down = true;
			}
		}
	}
}