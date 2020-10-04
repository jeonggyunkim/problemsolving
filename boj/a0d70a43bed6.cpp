#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int c = b;

	for (int i = 0; i < 3; ++i) {
		cout << a * (c % 10) << endl;
		c /= 10;
	}
	cout << a * b << endl;

	return 0;
}