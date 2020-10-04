#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B;
	cin >> A >> B;
	double M = (B - A) / 400.0;

	cout.precision(30);
	cout << 1 / (1 + pow(10, M));
}