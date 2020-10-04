#include <iostream>

int main() {
	int n;
	char seq[203];
	while (scanf("%d", &n), n) {
		scanf("%s", seq);
		int t = 0;
		while (seq[t++]);
		t /= n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < t; ++j) {
				if (j & 1) printf("%c", seq[(n - 1 - i) + j * n]);
				else printf("%c", seq[i + j * n]);
			}
		}
		printf("\n");
	}
}