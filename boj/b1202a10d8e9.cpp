#include <iostream>
using namespace std;

int main() {
	int max = 0;
	int maxi = 1;
	for (int i = 1; i <= 9; ++i) {
		int t;
		cin >> t;
		if (t > max) {
			max = t;
			maxi = i;
		}
	}

	cout << max << endl;
	cout << maxi << endl;

	return 0;
}
