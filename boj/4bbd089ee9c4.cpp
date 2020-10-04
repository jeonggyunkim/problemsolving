#include <iostream>
using namespace std;

int main() {

	int a;
	int b;
	cin >> a >> b;
	while (a + b) {
		cout << a + b << endl;
		cin >> a >> b;
	}

	return 0;
}