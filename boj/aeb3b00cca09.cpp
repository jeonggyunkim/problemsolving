#include <iostream>
using namespace std;

int main() {
	unsigned int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {

		unsigned int j2, j1;
		int j = 0;
		unsigned int m;
		unsigned int p = 0;
		cin >> j1 >> j2;
		unsigned int k = j2 - j1;
		while (k > p) {
			++j;
			m = j / 2;
			if (j % 2 == 1) {
				p = (m + 1) * (m + 1);
			}
			else {
				p = m * (m + 1);
			}
		}

		cout << j << endl;
	}

	return 0;
}