#include <iostream>
#define max(a, b) (a > b ? a : b)

int main() {
	char A[1010];
	char B[1010];

	scanf("%s", A);
	scanf("%s", B);

	int len_a = -1, len_b = -1;
	while (A[++len_a]);
	while (B[++len_b]);

	int LCS[1010][1010] = {0};

	for (int i = 1; i <= len_a; ++i) for (int j = 1; j <= len_b; ++j) {
		if (A[i - 1] == B[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
		else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
	}
	printf("%d\n", LCS[len_a][len_b]);
}