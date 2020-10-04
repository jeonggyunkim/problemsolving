#include <iostream>

int main() {
	int N, sum;
	char a;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; ++i) {
		sum = 0;
		while ((a = getchar()) != '\n') {
			if (a != ' ') sum += a - 64;
		}
		if (sum == 100) printf("PERFECT LIFE\n");
		else printf("%d\n", sum);
	}
	return 0;
}