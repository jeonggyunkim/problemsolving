#include <iostream>
using namespace std;

int main() {
	int test;
	cin >> test;

	int a;
	int b;

	for (int i = 0; i < test; i++) {
		cin >> a >> b;
		cout << a + b << endl;
	}

	return 0;
}