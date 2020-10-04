#include <iostream>

int main() {
	int n;
	int p[55];
	int child[55] = {0};
	int num[55] = {0};
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
		if (p[i] != -1) child[p[i]]++;
	}
	for (int i = 0; i < n; ++i) {
		if (child[i] == 0) {
			cnt++;
			int t = i;
			while (t != -1) {
				num[t]++;
				t = p[t];
			}
		}
	}
	scanf("%d", &n);
	if (p[n] != -1 && child[p[n]] == 1) cnt++;
	printf("%d\n", cnt - num[n]);
}