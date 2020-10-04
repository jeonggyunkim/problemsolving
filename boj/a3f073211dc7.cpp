#include <iostream>
using namespace std;

int main() {
	int arr[6] = {1, 1, 2, 2, 2, 8}, t;
	for (int i = 0; i < 6; ++i) {
		cin >> t;
		cout << arr[i] - t << ' ';
	}
}