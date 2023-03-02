#include <iostream>
#include <vector>
using namespace std;

int arr[3004];

int main() {
	int n, k;
	cin >> n >> k;

	arr[0] = -180 - k;
	for (int i = 0; i <= n; ++i) {
		arr[3 * i + 1] = arr[3 * i] + 18 * 60 + k;
		arr[3 * i + 2] = arr[3 * i + 1] + 3 * 60;
		arr[3 * i + 3] = arr[3 * i + 2] + 3 * 60;
	}
	vector<int> ans;
	for (int i = 0; i <= 3 * (n + 1); ++i) {
		if (arr[i] >= n * 24 * 60 && arr[i] < (n + 1) * 24 * 60) {
			ans.push_back(arr[i] % (24 * 60));
		}
	}
	cout << ans.size() << '\n';
	for (int u: ans) {
		printf("%02d:%02d\n", u / 60, u % 60);
	}
}