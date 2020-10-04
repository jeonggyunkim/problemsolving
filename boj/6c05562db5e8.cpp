#include <iostream>
#include <algorithm>

int main() {
	int arr[9];
	for (int i = 0; i < 9; ++i) scanf("%d", arr + i);
	std::sort(arr, arr + 9);

	int n[7];
	for (n[0] = 0; n[0] < 9; ++n[0])
	for (n[1] = n[0] + 1; n[1] < 9; ++n[1])
	for (n[2] = n[1] + 1; n[2] < 9; ++n[2])
	for (n[3] = n[2] + 1; n[3] < 9; ++n[3])
	for (n[4] = n[3] + 1; n[4] < 9; ++n[4])
	for (n[5] = n[4] + 1; n[5] < 9; ++n[5])
	for (n[6] = n[5] + 1; n[6] < 9; ++n[6]) {
		int sum = 0;
		for (int i = 0; i < 7; ++i) sum += arr[n[i]];
		if (sum == 100) {
			for (int i = 0; i < 7; ++i) printf("%d\n", arr[n[i]]);
			return 0;
		}
	}
}