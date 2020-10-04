#include <iostream>

int main() {
	int n;
	scanf("%d", &n);

	int num[1010];
	int lis[1010];
	for (int i = 0; i < n; ++i) scanf("%d", num + i);
	lis[0] = 1;

	int max, t;
	for (int i = 1; i < n; ++i) {
		max = 1;
		for (int j = 0; j < i; ++j) if (num[j] < num[i]) {
			t = lis[j] + 1;
			if (t > max) max = t;
		}
		lis[i] = max;
	}
	max = -1;
	for (int i = 0; i < n; ++i) if (lis[i] > max) max = lis[i];

	printf("%d\n", max);
}