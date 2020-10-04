#include <iostream>

int main() {
	int T, N;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d", &N);
		int num = 0;
		while (N) {
			N /= 5;
			num += N;
		}
		printf("%d\n", num);
	}
}