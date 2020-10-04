#include <iostream>
using namespace std;

int main() {
	int sum = 0, t;

	for (int i = 0; i < 4; ++i) {
		cin >> t;
		sum += t;
	}

	cout << sum / 60 << '\n';
	cout << sum % 60;
}