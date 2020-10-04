#include <iostream>
#include <algorithm>

int main() {
	int n;
	int arr[10001];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", arr + i);
	std::sort(arr, arr + n);

	int seq, max = -1;
	for (int i = 0; i < n; ++i) {
		seq = 1;
		for (int j = 1; j < 5; ++j) {
			if (i + j >= n) break;
			if (arr[i + j] <= arr[i] + 4) seq++;
			else break;
		}
		if (seq > max) max = seq;
	}

	if (max >= 5) printf("0");
	else printf("%d", 5 - max);
}