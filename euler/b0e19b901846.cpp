#include <iostream>
using namespace std;

int pow5(int n) {
	int ret = 1;
	for (int i = 0; i < 5; ++i) ret *= n;
	return ret;
}

int main() {
	int ans = 0;
	for (int i = 10; i < 1000000; ++i) {
		int sum = 0;
		int j = i;
		while (j) {
			sum += pow5(j % 10);
			j /= 10;
		}
		if (sum == i) ans += i;
	}
	cout << ans << endl;
}