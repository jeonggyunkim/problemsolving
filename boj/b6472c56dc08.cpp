#include <iostream>
using namespace std;

int main() {
	int test;
	cin >> test;

	int a, b;
	for (int i = 0; i < test; i++) {
		cin >> a >> b;
		cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << endl;
	}

	return 0;
}