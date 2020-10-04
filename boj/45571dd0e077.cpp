#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int arr[8] = {};
	for (int i = 0; i < m; ++i) arr[i] = 1;

	do {
		for (int i = 0; i < n; ++i) {
			if (arr[i]) cout << i + 1 << ' ';
		}
		cout << '\n';
	} while (prev_permutation(arr, arr + n));
}