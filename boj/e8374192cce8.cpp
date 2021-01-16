#include <iostream>
using namespace std;

int main() {
	int arr[4], sum = 0, ans = 99999;
	for (int i = 0; i < 4; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			ans = min(ans, abs(sum - 2 * (arr[i] + arr[j])));
		}
	}
	cout << ans;
}