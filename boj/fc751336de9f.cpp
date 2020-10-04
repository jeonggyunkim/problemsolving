#include <iostream>
#include <cmath>

int main() {
	bool p[1000001] = {1, 1, 0};
	int i = 0;
	while (i <= 1000000) {
		if (p[i] == 1) while (p[++i] == 1);
		else {
			for (int j = 2 * i; j <= 1000000; j += i) {
				p[j] = 1;
			}
			++i;
		}
	}

	int n;
	while (scanf("%d", &n), n) {
		i = 3;
		int j = n - i;
		while (i <= j) {
			if (p[i] == 0 && p[j] == 0) {
				printf("%d = %d + %d\n", n, i, j);
				break;
			}
			i += 2; j -= 2;
		}
	}
}