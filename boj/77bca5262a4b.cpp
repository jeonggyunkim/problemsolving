#include <iostream>

int main() {
	char A[55];
	char B[55];
	scanf("%s %s", A, B);

	int len_a = -1, len_b = -1;
	while (A[++len_a]);
	while (B[++len_b]);

	int min = 100, cnt;
	for (int i = 0; i <= len_b - len_a; ++i) {
		cnt = 0;
		for (int j = 0; j < len_a; ++j) {
			if (A[j] != B[i + j]) cnt++;
		}
		if (cnt < min) min = cnt;
	}
	printf("%d\n", min);
}