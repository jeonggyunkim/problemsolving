#include <iostream>
using namespace std;

int main() {
	double a, b, c = 299792458;
	cin >> a >> b;
	cout.precision(10);
	cout << (a + b) / (1 + a * b / c / c);
}