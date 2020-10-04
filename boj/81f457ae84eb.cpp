#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int a = 0, b = 1, c;
	for (int i = 0; i < N; ++i) {
		c = (a + b) % 15746;
		a = b;
		b = c;
	}
	cout << c << endl;

	return 0;
}