#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int min = 101;
	for (int i = 1; i <= 7; ++i) {
		int t;
		cin >> t;
		if (t % 2 == 1) {
			sum += t;
			if (t < min) {
				min = t;
			}
		}
	}

	if (sum) {
		cout << sum << endl;
		cout << min << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}
