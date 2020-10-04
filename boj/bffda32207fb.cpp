#include <iostream>

int main() {
	int N, B;
	scanf("%d %d", &N, &B);

	char arr[32];
	int i = 0, j;
	while (N) {
		j = N % B;
		if (j < 10) arr[i++] = '0' + j;
		else arr[i++] = 'A' + j - 10;
		N /= B;
	}
	while (i >= 1) printf("%c", arr[--i]);
	printf("\n");
}