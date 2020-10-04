#include <iostream>
using namespace std;

int main() {
	int t, sum = 0;
	for (int i = 0; i < 5; ++i) {
		cin >> t;
		if (t < 40) {
			t = 40;
		}
		sum += t;
	}

	cout << sum / 5;
}