#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	bool b;
	if (N % 4 == 0) {
		if (N % 100 == 0) {
			if (N % 400 == 0) b = 1;
			else b = 0;
		}
		else b = 1;
	}
	else b = 0;

	cout << b << endl;

	return 0;
}