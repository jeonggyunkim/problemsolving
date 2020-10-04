#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[80001] = {};
	for (int i = 1; i <= 80000; ++i) {
		if (i % 3 == 0 || i % 7 == 0) arr[i] = arr[i - 1] + i;
		else arr[i] = arr[i - 1];
	}

	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		cout << arr[n] << '\n';
	}
}