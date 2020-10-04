#include <iostream>

int n;
int input[22];
int cnt = 0;

void rec(int d, int r) {
	if (d == n) return;
	if (input[d] == r) cnt++;
	rec(d + 1, r);
	rec(d + 1, r - input[d]);
}

int main() {
	int s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; ++i) scanf("%d", input + i);
	rec(0, s);
	printf("%d\n", cnt);
}