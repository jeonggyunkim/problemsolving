#include <iostream>
#include <algorithm>
using namespace std;

int w[8], arr[8];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> w[i];
		arr[i] = i;
	}

	int ans = 0;
	do {
		int sum = 0, b = 1;
		for (int i = 0; i < n; ++i) {
			sum += w[arr[i]];
			if (sum < k * (i + 1)) b = 0;
		}
		if (b) ans++;
	} while (next_permutation(arr, arr + n));
	cout << ans;
}