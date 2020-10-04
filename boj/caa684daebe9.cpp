#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int w[10][10], arr[10];
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &w[i][j]);

	for (int i = 0; i < n; ++i) arr[i] = i;
	int min = (1 << 30);
	while (next_permutation(arr, arr + n)) {
		int t = 0;
		bool brk = false;
		for (int i = 0; i < n - 1; ++i) {
			int r = w[arr[i]][arr[i + 1]];
			if (r == 0) {
				brk = true;
				break;
			}
			else t += r;
		}
		int r = w[arr[n - 1]][arr[0]];
		if (r == 0) brk = true;
		else t += r;

		if (brk) continue;
		if (t < min) min = t;
	}
	printf("%d\n", min);
}