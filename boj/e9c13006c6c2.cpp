#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int t;
	int min = 1000000;
	int max = -1000000;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t < min) {
			min = t;
		}
		if (t > max) {
			max = t;
		}
	}

	cout << min << " " << max;

	return 0;
}
