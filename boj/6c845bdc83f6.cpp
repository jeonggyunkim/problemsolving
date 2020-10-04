#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long min, max, k, t, sq;
	int i, j, len, count = 0;

	cin >> min >> max;

	char prime[1000000] = { 1, 1, 0 };
	for (i = 0; i < 1000; ++i) {
		if (prime[i] == 0) {
			j = i;
			while ((k = i * j++) < 1000000) prime[k] = 1;
		}
	}

	len = max - min + 1;
	int* arr = new int[len];
	for (i = 0; i < len; ++i) arr[i] = 0;

	for (i = 0; i <= (int)sqrt(max); ++i) {
		if (prime[i] == 0) {
			sq = i;
			sq *= i;
			t = (min - 1) / sq + 1;
			k = t * sq - min;
			while (k < len) {
				arr[k] = 1;
				k += sq;
			}
		}
	}
	for (i = 0; i < len; ++i) {
		if (arr[i] == 0) ++count;
	}
	cout << count << endl;
	delete[] arr;
	return 0;
}