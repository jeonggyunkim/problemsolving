#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c[11][11];

int comb(int n, int k) {
	if (k == 0 || n == k) return 1;
	if (c[n][k] > 0) return c[n][k];
	return c[n][k] = comb(n - 1, k) + comb(n - 1, k - 1);
}

int main() {
	int n;
	cin >> n;
	n++;

	int i = 1;
	while (i <= 10 && n > comb(10, i)) {
		n -= comb(10, i);
		++i;
	}

	if (i > 10) {
		cout << -1;
		return 0;
	}

	vector<int> arr(10, 0);
	for (int j = 0; j < i; ++j) arr[j] = 1;
	for (int j = comb(10, i) - n - 1; j >= 0; --j) {
		prev_permutation(arr.begin(), arr.end());
	}

	for (int j = 0; j < 10; ++j) if (arr[j]) cout << 9 - j;
}