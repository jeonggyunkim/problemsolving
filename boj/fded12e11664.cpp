#include <iostream>

int arr[500001];
long long cnt = 0;

void merge(int* arr, int n) {
	if (n == 1) return;
	int n1 = n / 2, n2 = n - n / 2;
	merge(arr, n1);
	merge(arr + n1, n2);
	int* temp = new int[n];
	int i = 0, j = n1, k = 0;
	while (i < n1 && j < n) {
		if (arr[i] <= arr[j]) temp[k++] = arr[i++];
		else {
			temp[k++] = arr[j++];
			cnt += j - k;
		}
	}
	while (i < n1) temp[k++] = arr[i++];
	while (j < n) temp[k++] = arr[j++];
	for (int i = 0; i < n; ++i) arr[i] = temp[i];
	delete[] temp;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", arr + i);
	merge(arr, n);
	printf("%lld\n", cnt);
}