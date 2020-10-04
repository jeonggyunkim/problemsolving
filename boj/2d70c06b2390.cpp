#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[3];
	for (int i = 0; i < 3; ++i) cin >> arr[i];
	sort(arr, arr + 3);

	char buf[4];
	cin >> buf;

	for (int i = 0; i < 3; ++i) {
		cout << arr[buf[i] - 'A'] << ' ';
	}
}