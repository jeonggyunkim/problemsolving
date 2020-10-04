#include <iostream>
using namespace std;

int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int main() {
	int ans = 0;
	for (int i = 10; i <= 9999999; ++i) {
		int sum = 0;
		int j = i;
		while (j) {
			sum += fact[j % 10];
			j /= 10;
		}
		if (sum == i) ans += i;
	}
	cout << ans << endl;
}