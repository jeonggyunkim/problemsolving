#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int m = n;
	int cycle = 0;
	do {
		m = 10 * (m % 10) + ((m / 10) + (m % 10)) % 10;
		cycle++;
	} while (m != n);

	cout << cycle;
}