#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int R, B;
	cin >> R >> B;

	long long c = R + B, b = (R + 4) / 2;

	if (b * b - 4 * c == 0) {
		cout << b / 2 << ' ' << b / 2;
	}
	else {
		cout << (b + (int)sqrt(b * b - 4 * c)) / 2 << ' ';
		cout << (b - (int)sqrt(b * b - 4 * c)) / 2;
	}
}