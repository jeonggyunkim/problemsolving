#include <iostream>

int main() {
	char cd[5010];
	int num[5010] = {1}, n = -1;

	scanf("%s", cd);
	while (cd[++n]);
	if (cd[0] == '0') {
		printf("0\n");
		return 0;
	}


	for (int i = 1; i < n; ++i) {
		if (cd[i] > '0') num[i] = num[i - 1];
		if (cd[i - 1] == '1' || (cd[i - 1] == '2' && cd[i] <= '6')) {
			if (i != 1) num[i] = (num[i] + num[i - 2]) % 1000000;
			else num[i]++;
		}
	}
	printf("%d\n", num[n - 1]);
}