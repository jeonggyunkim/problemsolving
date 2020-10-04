#include <iostream>
using namespace std;

int main() {
	int N, r, c;
	scanf("%d %d %d", &N, &r, &c);
	int num = 0;
	int n = 1;
	while (r || c) {
		if (r & 1) num += (n << 1);
		if (c & 1) num += n;
		n <<= 2;
		r >>= 1;
		c >>= 1;
	}
	printf("%d\n", num);
	return 0;
}