#include <iostream>
using namespace std;

int main() {
	int arr[5];
	for (int i = 0; i < 5; ++i) cin >> arr[i];

	while (true) {
		for (int i = 0; i < 4; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				for (int i = 0; i < 5; ++i) cout << arr[i] << ' ';
				cout << '\n';
			}
		}
		bool fin = 1;
		for (int i = 0; i < 5; ++i) {
			if (i + 1 != arr[i]) fin = 0;
		}
		if (fin) break;
	}
}