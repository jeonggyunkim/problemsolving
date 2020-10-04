#include <iostream>

int main() {
	char buf[1001];
	int a = 0, b = 0;
	scanf("%s", buf);
	while (buf[++a]);
	scanf("%s", buf);
	while (buf[++b]);
	a >= b ? printf("go\n") : printf("no\n");

	return 0;
}