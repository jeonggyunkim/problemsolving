#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a = n / 300;
	n -= 300 * a;
	int b = n / 60;
	n -= 60 * b;
	int c = n / 10;
	n -= 10 * c;
	if (n != 0) {
		cout << -1 << endl;
	}
	else {
		cout << a << " " << b << " " << c << endl;
	}

	return 0;
}
