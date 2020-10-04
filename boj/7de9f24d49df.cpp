#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int h = 0;
	int block = 0;

	while (block <= n) {
		block += 2 * h * h + 2 * h + 1;
		h++;
	}
	cout << h - 1 << endl;

	return 0;
}