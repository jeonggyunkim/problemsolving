#include <iostream>
using namespace std;

int main() {
	int tc, n;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		printf("%d\n", n & 1 ? (n - (n + 2) / 3 + 2) / 2 + (n + 1) / 2 : (n - (n + 2) / 3 + 1) / 2 + n / 2);
	}
}