#include <iostream>
using namespace std;

int main() {
	int arr[10001];
	int zero[10001];
	int one[10001];
	int two[10001];

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", arr + i);

	two[0] = zero[0] = 0;
	one[0] = arr[0];

	for (int i = 1; i < n; ++i) {
		two[i] = one[i - 1] + arr[i];
		one[i] = zero[i - 1] + arr[i];
		if (zero[i - 1] > one[i - 1] && zero[i - 1] > two[i - 1]) zero[i] = zero[i - 1];
		else zero[i] = one[i - 1] > two[i - 1] ? one[i - 1] : two[i - 1];
	}

	if (zero[n - 1] > one[n - 1] && zero[n - 1] > two[n - 1]) printf("%d\n", zero[n - 1]);
	else {
		if (one[n - 1] > two[n - 1]) printf("%d\n", one[n - 1]);
		else printf("%d\n", two[n - 1]);
	}

	return 0;
}