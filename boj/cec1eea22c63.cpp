#include <iostream>

int main() {
	char arr[32];
	int B;
	scanf("%s", arr);
	scanf("%d", &B);

	int n = 0, i = 0;
	while (arr[i]) {
		n *= B;
		if (arr[i] <= '9') n += arr[i] - '0';
		else n += arr[i] - 'A' + 10;
		i++;
	}

	printf("%d\n", n);
}