#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	B += C % 60;
	if (B >= 60) {
		B -= 60;
		A += 1;
	}
	A += C / 60;
	A %= 24;

	cout << A << " " << B << endl;
}