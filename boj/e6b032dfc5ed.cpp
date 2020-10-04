#include <iostream>

int main() {
	int N;
	scanf("%d", &N);
	int* arr = new int[N];
	int* len = new int[N];

	for (int i = 0; i < N; ++i) scanf("%d", arr + i);
	for (int i = 0; i < N; ++i) {
		int m = 0;
		for (int j = 0; j < i; ++j) if (arr[j] > arr[i] && len[j] > m) m = len[j];
		len[i] = m + 1;
	}

	int max = 0;
	for (int i = 0; i < N; ++i) if (max < len[i]) max = len[i];

	printf("%d\n", max);

	delete[] arr;
	delete[] len;

	return 0;
}