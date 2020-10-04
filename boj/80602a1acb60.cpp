#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 0) {
		cout << 1 << endl;
		return 0;
	}

	int arr[10] = {};

	while (n != 0) {
		arr[n % 10] += 1;
		n /= 10;
	}

	arr[6] = (arr[6] + arr[9] + 1) / 2;
	arr[9] = 0;

	int max = 0;
	for (int i = 0; i < 10; ++i) {
		if (arr[i] > max) max = arr[i];
	}
	cout << max << endl;

	return 0;
}