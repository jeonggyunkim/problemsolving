#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int temp;
	if (b < a) {
		temp = a;
		a = b;
		b = temp;
	}
	if (c < b) {
		temp = b;
		b = c;
		c = temp;
	}
	if (b < a) {
		temp = a;
		a = b;
		b = temp;
	}

	cout << b;

	return 0;
}