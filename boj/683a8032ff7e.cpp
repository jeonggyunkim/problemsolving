#include <iostream>
#include <algorithm>
using namespace std;

int arr[500000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);

	cin >> m;
	while (m--) {
		cin >> t;
		cout << binary_search(arr, arr + n, t) << ' ';
	}
}