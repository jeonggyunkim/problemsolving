#include <iostream>
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	long long p = 2;
	for (int i = 0; i < a; ++i) p *= 2;

	char buf[20];
	for (int e = a + 1; e < 64; ++e) {
		sprintf(buf, "%lld", p);
		if (buf[0] == b + '0') {
			printf("%d", e);
			return 0;
		}
		p *= 2;
	}
	printf("0");
}