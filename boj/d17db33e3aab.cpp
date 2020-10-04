#include <iostream>
#define max(a, b) (a > b ? a : b)

int main() {
	int tc, n, stick[2][100010];
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; ++i) for (int j = 0; j < n; ++j) scanf("%d", &stick[i][j]);
		int a = 0, b = 0, c = 0, ta, tb, tc;
		for (int i = 0; i < n; ++i) {
			ta = a, tb = b, tc = c;
			a = max(tb, tc) + stick[0][i];
			b = max(ta, tc) + stick[1][i];
			c = max(ta, tb);
		}
		printf("%d\n", max(a, b));
	}
}