#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[12];
	int n;
	cin >> n;

	int i = 0;
	while (n != 0) {
		arr[i] = n % 10;
		n /= 10;
		++i;
	}
	sort(arr, arr + i);

	for (int j = i - 1; j >= 0; --j) {
		cout << arr[j];
	}

	return 0;
}