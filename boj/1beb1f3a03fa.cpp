#include <iostream>

int main() {
	int n, w, i, j, k, count, max;
	char ori[129];
	char temp[129];
	char ans[129];

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s", ori);
		scanf("%d", &w);
		max = -1;
		for (j = 0; j < w; ++j) {
			scanf("%s", temp);
			k = 0;
			count = 0;
			while (temp[k]) {
				if (temp[k] == ori[k]) count++;
				k++;
			}
			if (max < count) {
				max = count;
				k = 0;
				while (temp[k]) {
					ans[k] = temp[k];
					k++;
				}
				ans[k] = 0;
			}
		}
		printf("%s\n", ans);
	}

	return 0;
}