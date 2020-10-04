#include <iostream>

char cloth[1000005] = {};
char size[1000005] = {};

int main() {
	int J, A, t;
	char c;
	scanf("%d %d", &J, &A);
	for (int i = 1; i <= J; ++i) {
		scanf(" %c", cloth + i);
	}
	for (int i = 0; i < A; ++i) {
		scanf(" %c %d", &c, &t);
		if (size[t] < c) size[t] = c;
	}
	int count = 0;
	for (int i = 1; i <= J; ++i) {
		if (size[i] && cloth[i] <= size[i]) count++;
	}
	printf("%d\n", count);
}