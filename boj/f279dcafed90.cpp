#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int result = 1;
	int temp = 0;
	for (int i = 1; i <= a; ++i) {
		temp += i;
	}
	result *= temp;
	result %= 14579;
	for (int i = a + 1; i <= b; ++i) {
		temp += i;
		result *= temp;
		result %= 14579;
	}
	cout << result << endl;

	return 0;
}