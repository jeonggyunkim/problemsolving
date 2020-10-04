#include <iostream>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int a[50];
	for (int i = 0; i < M; ++i) {
		scanf("%d", a + i); a[i]--;
	}
	int total = 0;
	for (int i = 0; i < M; ++i) {
		total += (a[i] <= N / 2) ? a[i] : N - a[i];
		for (int j = i + 1; j < M; ++j) {
			a[j] -= a[i] + 1;
			if (a[j] < 0) a[j] += N;
		}
		N--;
	}
	printf("%d\n", total);
}