#include <iostream>
using namespace std;

int arr[300010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		cin >> arr[i];
	}

	int low = 0, high = 1e9;
	while (high - low != 1) {
		int mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < m; ++i) {
			cnt += (arr[i] + mid - 1) / mid;
		}
		if (cnt > n) low = mid;
		else high = mid;
	}

	cout << high;
}