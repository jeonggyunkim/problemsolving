#include <iostream>
using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	C += D % 60;
	if (C >= 60) {
		C -= 60;
		B += 1;
	}
	B += (D % 3600) / 60;
	if (B >= 60) {
		B -= 60;
		A += 1;
	}
	A += D / 3600;
	A %= 24;

	cout << A << " " << B << " " << C << endl;

	return 0;
}