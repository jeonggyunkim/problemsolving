#include <iostream>

int main() {
	int n, m, t;
	while (scanf("%d %d", &n, &m), n | m) {
		int arr[1000000];
		for (int i = 0; i < n; ++i) scanf("%d", arr + i);

		int cnt = 0;
		int i = 0;
		while (m--) {
			scanf("%d", &t);

			while (i < n) {
				if (arr[i] == t) {
					cnt++;
					i++;
					break;
				}
				else if (arr[i] < t) i++;
				else break;
			}
		}

		printf("%d\n", cnt);
	}
}