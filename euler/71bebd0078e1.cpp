#include <iostream>
using namespace std;

int len(int n) {
	while (n % 2 == 0) n /= 2;
	while (n % 5 == 0) n /= 5;
	if (n == 1) return 0;
	int len = 1;
	int p = 9 % n;
	while (p) {
		len++;
		p = (10 * p + 9) % n;
	}
	return len;
}

int main() {
	int ans, large = -1;
	for (int i = 2; i <= 999; ++i) {
		int t = len(i);
		if (large < t) {
			large = t;
			ans = i;
		}
	}
	cout << ans << endl;
}