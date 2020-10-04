#include <iostream>

int main() {
	char buf[1000010];
	scanf("%s", buf);
	int l = -1;
	while (buf[++l]);

	int i = l % 3, t;
	for (int j = 0; j < i; ++j) {
		t <<= 1;
		t += (buf[j] & 1);
	}
	if (i) printf("%d", t);
	while (i < l) {
		printf("%d", ((buf[i] & 1) << 2) | ((buf[i + 1] & 1) << 1) | (buf[i + 2] & 1));
		i += 3;
	}
	printf("\n");
}