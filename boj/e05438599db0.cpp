#include <iostream>

int main() {
	int n;
	scanf("%d", &n);

	int arr[3] = {1}, t[3];

	while (n--) {
		t[0] = arr[0];
		t[1] = arr[1];
		t[2] = arr[2];
		arr[0] = (t[0] + t[1] + t[2]) % 9901;
		arr[1] = (t[0] + t[2]) % 9901;
		arr[2] = (t[0] + t[1]) % 9901;
	}
	printf("%d\n", (arr[0] + arr[1] + arr[2]) % 9901);
}