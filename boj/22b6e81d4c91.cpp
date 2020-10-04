#include <iostream>

int main() {
	char num[333555];
	scanf("%s", num);

	if (num[0] >= '4') {
		printf("1");
		printf("%d", (num[0] >> 1) & 1);
		printf("%d", num[0] & 1);
	}
	else {
		if (num[0] >= '2') {
			printf("1");
			num[0] == '3' ? printf("1") : printf("0");
		}
		else {
			num[0] == '1' ? printf("1") : printf("0");
		}
	}

	int i = 1;
	while (num[i]) {
		printf("%d", (num[i] >> 2) & 1);
		printf("%d", (num[i] >> 1) & 1);
		printf("%d", num[i] & 1);
		++i;
	}
}