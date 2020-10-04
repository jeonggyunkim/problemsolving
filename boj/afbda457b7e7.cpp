#include <iostream>
using namespace std;

int main() {
	int t;
	int min1 = 2000;
	int min2 = 2000;
	for (int i = 0; i < 3; ++i) {
		cin >> t;
		if (min1 > t) min1 = t;
	}
	for (int i = 0; i < 2; ++i) {
		cin >> t;
		if (min2 > t) min2 = t;
	}
	cout << min1 + min2 - 50 << endl;

	return 0;
}