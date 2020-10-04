#include <iostream>

int main() {
	int t, p;
	int max[20] = {0};

	int n;
	scanf("%d", &n);

	int maxp = -1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &t, &p);
		if (i + t - 1 <= n && max[i - 1] + p > max[i + t - 1]) max[i + t - 1] = max[i - 1] + p;
		for (int j = 0; j < i; ++j) if (max[j] > max[i]) max[i] = max[j];
		if (max[i] > maxp) maxp = max[i];
	}

	printf("%d\n", maxp);
}