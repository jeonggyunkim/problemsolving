#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	for (int q = 0; q <= n; ++q) {
		int high = 0, low = 0;
		for (int i = 0; i < n; ++i) {
			if (arr[i] >= q) high++;
			if (arr[i] <= q) low++;
		}
		if (high >= q && low >= n - q) cout << q << '\n';
	}
}