#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int per[8];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < m; ++i) per[i] = 1;

	do {
		for (int i = 0; i < n; ++i) {
			if (per[i]) cout << arr[i] << ' ';
		}
		cout << '\n';
	} while (prev_permutation(per, per + n));
}