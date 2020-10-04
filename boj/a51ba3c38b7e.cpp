#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, k, t;
	scanf("%d %d %d", &n, &m, &k);

	t = min(n / 2, m);
	if (n > 2 * m) k -= n - 2 * m;
	else k -= m - n / 2;

	if (k <= 0) printf("%d\n", t);
	else printf("%d\n", t - (k + 2) / 3);
}