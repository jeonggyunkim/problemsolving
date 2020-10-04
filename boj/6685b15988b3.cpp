#include <iostream>
#include <cmath>
#define EPS 1e-9
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << (int)(M_PI / atan(1.0 / n) - EPS);
}