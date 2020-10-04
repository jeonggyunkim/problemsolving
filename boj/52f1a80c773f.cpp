#include <iostream>

void matmul(long long s[8][8], long long a[8][8]) {
	long v[8][8];
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			long long n = 0;
			for (int k = 0; k < 8; ++k) {
				n += s[i][k] * a[k][j];
				n %= 1000000007;
			}
			v[i][j] = n;
		}
	}
	for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j) s[i][j] = v[i][j];
}

void mul(long long a[8][8], int n) {
	if (n == 1) return;
	if (n % 2 == 0) {
		matmul(a, a);
		mul(a, n / 2);
	}
	else {
		long long r[8][8];
		for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j) r[i][j] = a[i][j];
		mul(a, --n);
		matmul(a, r);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	long long mat[8][8] = {
	{0, 1, 1},
	{1, 0, 1, 1},
	{1, 1, 0, 1, 1},
	{0, 1, 1, 0, 1, 0, 1},
	{0, 0, 1, 1, 0, 1, 1},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 1, 1, 0}
	};

	mul(mat, n);

	printf("%lld\n", mat[0][0]);
}