#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int a = 1, b = 2, t;
	while (b <= 4000000) {
		if (b % 2 == 0) sum += b;
		t = b;
		b += a;
		a = t;
	}
	cout << sum << endl;
}
