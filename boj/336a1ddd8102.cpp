#include <iostream>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	cout << (b - a + 1) * (a + b) / 2;
}