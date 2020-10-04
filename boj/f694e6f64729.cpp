#include <iostream>
using namespace std;

int main() {
	int remain[42] = {};

	int t;
	for (int i = 0; i < 10; ++i) {
		cin >> t;
		remain[t % 42] = 1;
	}

	int count = 0;
	for (int i = 0; i < 42; ++i) count += remain[i];
	cout << count << endl;

	return 0;
}