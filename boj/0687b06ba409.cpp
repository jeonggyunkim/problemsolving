#include <iostream>

int main() {
	int n, sum, t1, t2, d1 = 0, d2 = 0;
	scanf("%d", &n);

	int sq[101][101];
	char check[10001] = {0};
	bool magic = true;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		scanf("%d", &sq[i][j]);
		check[sq[i][j]] = 1;
	}
	for (int i = 1; i <= n * n; ++i) if (check[i] == 0) magic = false;

	sum = n * (n * n + 1) / 2;
	for (int i = 0; i < n; ++i) {
		t1 = 0; t2 = 0;
		for (int j = 0; j < n; ++j) {
			t1 += sq[i][j];
			t2 += sq[j][i];
		}
		if (t1 != sum || t2 != sum) magic = false;
		d1 += sq[i][i];
		d2 += sq[n - 1 - i][i];
	}
	if (d1 != sum || d2 != sum) magic = false;

	if (magic) printf("TRUE\n");
	else printf("FALSE\n");
}
