#include <iostream>
using namespace std;

int main() {
	int sum = 0, t;
	for (int i = 0; i < 5; ++i) {
		cin >> t;
		sum += t;
	}
	cout << sum;
}