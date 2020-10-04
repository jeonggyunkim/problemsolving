#include <iostream>

char arr[1030][2050];

int x(int n) {
	static int mem[20] = {};
	if (mem[n] > 0) return mem[n];
	if (n == 1) return mem[n] = 1;
	return mem[n] = x(n - 1) * 2 + 3;
}

int y(int n) {
	static int mem[20] = {};
	if (mem[n] > 0) return mem[n];
	if (n == 1) return mem[n] = 1;
	return mem[n] = y(n - 1) * 2 + 1;
}

void star(int a, int b, int n) {
	if (n % 2 == 1) {
		for (int i = 0; i < y(n); ++i) {
			arr[a + i][b + i] = '*';
			arr[a + i][b - i] = '*';
			arr[a + y(n) - 1][b + i] = '*';
			arr[a + y(n) - 1][b - i] = '*';
		}
	}
	else {
		for (int i = 0; i < y(n); ++i) {
			arr[a - i][b + i] = '*';
			arr[a - i][b - i] = '*';
			arr[a - y(n) + 1][b + i] = '*';
			arr[a - y(n) + 1][b - i] = '*';
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	int a = x(n);
	int b = y(n);

	for (int i = 0; i < b; ++i) {
		int k = i;
		if (n % 2 == 1) {
			k = b - i - 1;
		}
		for (int j = 0; j < a - i; ++j) arr[k][j] = ' ';
		arr[k][a - i] = 0;
	}

	int cx = x(n) / 2;
	int cy;
	if (n % 2 == 1) cy = 0;
	else cy = y(n) - 1;

	for (int i = n; i > 0; --i) {
		star(cy, cx, i);
		if (i % 2 == 1) cy = cy + y(i) - 2;
		else cy = cy - y(i) + 2;
	}

	for (int i = 0; i < b; ++i) {
		printf("%s\n", arr[i]);
	}
}