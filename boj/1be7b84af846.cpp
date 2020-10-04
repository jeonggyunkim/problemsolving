#include <iostream>
using namespace std;

int num(int k, int n) {
	static int mem[15][15] = {};

	if (mem[k][n] > 0) {
		return mem[k][n];
	}
	if (k == 0) {
		return mem[k][n] = n;
	}
	if (n == 1) {
		return mem[k][n] = 1;
	}
	return mem[k][n] = num(k - 1, n) + num(k, n - 1);
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {

		int k, n;
		cin >> k >> n;
		cout << num(k, n) << endl;
	}

	return 0;
}