#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int arr[10000];
	for (int i = 0; i < n; ++i) scanf("%d", arr + i);

	if (next_permutation(arr, arr + n)) {
		for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
	}
	else printf("-1");
}