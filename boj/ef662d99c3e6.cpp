#include <iostream>
using namespace std;

int main() {
	int max = 0;
	int maxa = 1;
	int maxb = 1;
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			int t;
			cin >> t;
			if (t > max) {
				max = t;
				maxa = i;
				maxb = j;
			}
		}
	}

	cout << max << endl;
	cout << maxa << " " << maxb << endl;

	return 0;
}
