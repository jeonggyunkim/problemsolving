#include <iostream>
#include <memory.h>

int sum[503][503] = {0};
int price[503][503] = {0};

int cal(int s, int f) {
	if (sum[s][f] != 0) return sum[s][f];
	if (s == f) return 0;
	int min = (1 << 30), t;
	for (int i = s; i < f; ++i) {
		t = cal(s, i) + cal(i + 1, f);
		if (t < min) min = t;
	}
	return sum[s][f] = min + price[s][f];
}

int main() {
	int tc, n;
	scanf("%d", &tc);

	while (tc--) {
		memset(sum, 0, sizeof(sum));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &price[i][i]);
		}
		for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) price[i][j] = price[i][j - 1] + price[j][j];
		printf("%d\n", cal(0, n - 1));
	}
}
