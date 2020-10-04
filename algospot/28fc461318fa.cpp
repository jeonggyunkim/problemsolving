#include <iostream>

int main() {
	int n;
	char name[52];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", name);
		printf("Hello, %s!\n", name);
	}
}
