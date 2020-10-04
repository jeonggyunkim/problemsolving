#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int i = 1;
	n--;
	while (n > 0) {
		n -= 6 * i;
		++i;
	}
	cout << i << endl;

	return 0;
}