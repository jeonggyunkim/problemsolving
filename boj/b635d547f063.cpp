#include <iostream>
using namespace std;

int main() {
	int k;
	cin >> k;
	k--;

	int n = 2, dig = 1;
	while (k >= n) {
		 k -= n;
		 n *= 2;
		 dig++;
	}

	for (int i = dig - 1; i >= 0; --i) {
		if (k & (1 << i)) cout << 7;
		else cout << 4;
	}
}