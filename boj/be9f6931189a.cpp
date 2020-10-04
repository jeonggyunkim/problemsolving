#include <iostream>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == 1) printf("1");
	else if (n == 2) {
		if (m >= 7) printf("4");
		else if (m >= 5) printf("3");
		else if (m >= 3) printf("2");
		else printf("1");
	}
	else {
		if (m >= 7) printf("%d", m - 2);
		else if (m > 4) printf("4");
		else printf("%d", m);
	}
}