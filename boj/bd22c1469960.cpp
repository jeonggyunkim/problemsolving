#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a = 0, b = 1, c;
	while (n--) {
		c = (a + b) % 10007;
		a = b;
		b = c;
	}
	cout << b;
}