#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int r = 0;
	while (N != 0) {
		if (N % 2 == 1) {
			r++;
		}
		N /= 2;
	}
	cout << r << endl;

	return 0;
}