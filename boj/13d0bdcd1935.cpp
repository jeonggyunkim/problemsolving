#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	a--; b--;

	cout << abs(a % 4 - b % 4) + abs(a / 4 - b / 4);
}
