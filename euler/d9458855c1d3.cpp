#include <iostream>
using namespace std;

int arr[400];

int main() {
	int len = 1;
	arr[0] = 1;
	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < len; ++j) {
			arr[j] *= 2;
		}
		for (int j = 0; j < len; ++j) {
			if (arr[j] >= 10) {
				arr[j] -= 10;
				arr[j + 1]++;
			}
		}
		if (arr[len]) len++;
	}
	int ans = 0;
	for (int i = 0; i < len; ++i) ans += arr[i];
	cout << ans << endl;
}