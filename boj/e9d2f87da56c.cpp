#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, arr[8];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", arr + i);
	sort(arr, arr + n);

	int max = -1;
	while (next_permutation(arr, arr + n)) {
		int t = 0;
		for (int i = 0; i < n - 1; ++i) t += abs(arr[i] - arr[i + 1]);
		if (t > max) max = t;
	}
	printf("%d\n", max);
}