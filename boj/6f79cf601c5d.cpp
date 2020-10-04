#include <iostream>
using namespace std;

int main() {
	int count[10] = {};

	int p = 1;
	for (int i = 1; i <= 3; ++i) {
		int t;
		cin >> t;
		p *= t;
	}

	while (p != 0) {
		count[p % 10] += 1;
		p /= 10;
	}

	for (int i = 0; i < 10; ++i) {
		cout << count[i] << endl;
	}

	return 0;
}
