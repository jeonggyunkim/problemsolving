#include <iostream>
using namespace std;

int main() {
	for (int a = 1; a <= 1000; ++a) {
		for (int b = a; b <= 1000 - a; ++b) {
			int c = 1000 - a - b;
			if (a * a + b * b == c * c) {
				cout << a * b * c << endl;
				return 0;
			}
		}
	}
}