#include <iostream>

int main() {
	int arr[100010], n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", arr + i);

	int sum = 0, max = 0;
	bool allneg = true;
	int maxnum = -10000;
	for (int i = 0; i < n; ++i) {
		if (arr[i] >= 0) allneg = false;
		if (maxnum < arr[i]) maxnum = arr[i];
		sum += arr[i];
		max = max > sum ? max : sum;
		if (sum < 0) sum = 0;
	}
	if (allneg) printf("%d\n", maxnum);
	else printf("%d\n", max);
}