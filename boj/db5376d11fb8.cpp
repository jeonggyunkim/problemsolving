#include <iostream>

int pow(int base, int index, int mod = 10) {
	int r = 1;
	while (index != 0) {
		if (index & 1 != 0) r = (r * base) % mod;
		base = (base * base) % mod;
		index >>= 1;
	}
	return r;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);

		int com = pow(a, b);
		if (com == 0) printf("10\n");
		else printf("%d\n", com);
	}

	return 0;
}