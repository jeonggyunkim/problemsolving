#include <iostream>
using namespace std;

int main() {
	int n, a;
	int count = 0;
	cin >> n;

	n %= 10;

	for (int i = 0; i < 5; ++i) {
		cin >> a;
		if (a == n) count++;
	}

	cout << count << endl;

	return 0;
}