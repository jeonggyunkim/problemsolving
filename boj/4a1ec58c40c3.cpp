#include <iostream>
using namespace std;

int main() {
	int off, on;
	int max = 0;
	int cur = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> off >> on;
		cur -= off;
		cur += on;

		if (max < cur) {
			max = cur;
		}
	}

	cout << max << endl;

	return 0;
}