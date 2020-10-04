#include <iostream>

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		char color[1001] = {0};
		int arr[1001];
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", arr + i);

		int cnt = 0, t;
		for (int i = 1; i <= n; ++i) {
			if (!color[i]) {
				cnt++;
				color[i] = 1;
				t = i;
				while (!color[arr[t]]) {
					color[arr[t]] = 1;
					t = arr[t];
				}
			}
		}
		printf("%d\n", cnt);
	}
}