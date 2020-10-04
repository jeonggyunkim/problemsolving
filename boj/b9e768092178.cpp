#include <iostream>
using namespace std;

char a[101], b[101];

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		scanf("%s %s", a, b);
		int ans = 0;
		for (int i = 0; a[i]; ++i) {
			ans += (a[i] != b[i]);
		}
		printf("Hamming distance is %d.\n", ans);
	}
}