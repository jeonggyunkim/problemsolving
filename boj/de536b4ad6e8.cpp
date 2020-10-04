#include <iostream>
using namespace std;

int main() {
	int arr[1001];
	int max[1001];

	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) scanf("%d", arr + i);

	arr[0] = max[0] = 0;
	max[1] = arr[1];

	int t;
	for (int i = 2; i <= N; ++i) {
		t = -1;
		for (int j = 0; j < i; ++j) if (t < arr[i - j] + max[j]) t = arr[i - j] + max[j];
		max[i] = t;
	}
	printf("%d\n", max[N]);
	return 0;
}