#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double l;
	cin >> l;

	cout.precision(30);
	cout << l * l * sin(2 * M_PI / 3) / 2;
}