#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	int sum = 0;
	int count[100] = {};

	for (int i = 0; i < 10; ++i) {
		cin >> t;
		sum += t;
		count[(t - 10) / 10]++;
	}

	int max = 0;
	int maxi = 0;

	for (int i = 0; i < 100; ++i) {
		if (count[i] > max) {
			max = count[i];
			maxi = i;
		}
	}

	cout << sum / 10 << endl;
	cout << (maxi + 1) * 10 << endl;

	return 0;
}