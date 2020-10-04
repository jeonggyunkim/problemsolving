#include <iostream>
#include <algorithm>
using namespace std;

int num[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
int prime[7] = {2, 3, 5, 7, 11, 13, 17};

int main() {
	long long sum = 0;
	do {
		bool pos = 1;
		for (int i = 0; i < 7; ++i) {
			if ((100 * num[i + 1] + 10 * num[i + 2] + num[i + 3]) % prime[i]) pos = 0;
		}
		if (pos) {
			long long now = 0;
			for (int i = 0; i < 10; ++i) {
				now *= 10;
				now += num[i];
			}
			sum += now;
		}
	} while (next_permutation(num, num + 10));
	cout << sum << endl;
}