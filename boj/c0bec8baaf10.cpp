#include <iostream>
using namespace std;

int arr[50];

int main() {
	int l, n;
	cin >> l;
	for (int i = 0; i < l; ++i) cin >> arr[i];
	cin >> n;

	int ans = 1;
	for (int i = n; ; ++i) {
		bool brk = 0;
		for (int j = 0; j < l; ++j) if (arr[j] == i) brk = 1;
		if (brk) {
			ans *= i - n;
			break;
		}
	}
	for (int i = n; i >= 1; --i) {
		bool brk = 0;
		for (int j = 0; j < l; ++j) if (arr[j] == i) brk = 1;
		if (brk) {
			ans *= n - i;
			break;
		}
	}
	if (ans) ans--;
	cout << ans;
}