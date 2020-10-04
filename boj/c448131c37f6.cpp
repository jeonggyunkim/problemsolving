#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int i = 1;
	while (n > 0) {
		n -= i;
		++i;
	}
	n += i - 1;
	if (i % 2 == 1) {
		cout << n << "/" << i - n << endl;
	}
	else {
		cout << i - n << "/" << n << endl;
	}

	return 0;
}