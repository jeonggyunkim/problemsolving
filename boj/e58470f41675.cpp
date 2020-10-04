#include <iostream>
#include <cmath>

int seq(int n) {
	static int mem[1000001] = { 1, 0 };
	if (mem[n] > 0) return mem[n];
	return mem[n] = (seq((int)((double)n - sqrt(n))) + seq((int)log(n)) + seq((int)(sin(n) * sin(n) * n))) % 1000000;
}

int main() {
	int n;
	while (scanf("%d", &n), n != -1) {
		printf("%d\n", seq(n));
	}
}