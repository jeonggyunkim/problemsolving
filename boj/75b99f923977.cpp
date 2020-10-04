#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int n3 = 0;
	int n5 = 0;
	while (n % 5 != 0 && n >= 0) {
		n -= 3;
		n3 += 1;
	}
	if (n < 0) {
		cout << -1;
		return 0;
	}
	n5 = n / 5;

	cout << n3 + n5;

	return 0;
}