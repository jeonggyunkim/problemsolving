#include <iostream>
using namespace std;

int main() {
	int a[5];
	int s = 0;

	for (int i = 0; i < 5; ++i) {
		cin >> a[i];
		s += a[i] * a[i];
	}
	cout << s % 10 << endl;

	return 0;
}