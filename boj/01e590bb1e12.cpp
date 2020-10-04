#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a < b) swap(a, b);
	int d = a - b;

	if (c <= d) printf("%d\n", 2 * (b + c));
	else {
		c -= d;
		if (c & 1) c--;
		printf("%d\n", 2 * (b + d) + c);
	}
}