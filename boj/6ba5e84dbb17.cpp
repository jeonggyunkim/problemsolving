#include <iostream>
using namespace std;

int main() {
	int arr[100001] = {};
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {
		int t = 0;
		arr[i] = 1000000;
		while (i - t * t >= 0) {
			if (arr[i] > arr[i - t * t] + 1) arr[i] = arr[i - t * t] + 1;
			++t;
		}
	}
	printf("%d\n", arr[N]);
	return 0;
}