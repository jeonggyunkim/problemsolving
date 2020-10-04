#include <iostream>

char img[64][64];

void quad(int y, int x, int n) {
	if (n == 1) {
		printf("%c", img[y][x]);
		return;
	}
	bool same = true;
	for (int i  = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (img[y + i][x + j] != img[y][x]) {
			same = false;
			break;
		}
	}
	if (same) printf("%c", img[y][x]);
	else {
		int nn = n >> 1;
		printf("(");
		quad(y, x, nn);
		quad(y, x + nn, nn);
		quad(y + nn, x, nn);
		quad(y + nn, x + nn, nn);
		printf(")");
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%s", img[i]);
	quad(0, 0, n);
}