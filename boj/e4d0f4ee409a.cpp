#include <iostream>

int main() {
	int n;
	char name[55], c;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		printf("String #%d\n", i + 1);
		scanf("%s", name);
		int j = 0;
		while (name[j]) {
			c = name[j] + 1;
			c -= c > 'Z' ? 26 : 0;
			printf("%c", c);
			j++;
		}
		printf("\n\n");
	}
}