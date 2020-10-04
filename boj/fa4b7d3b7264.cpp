#include <iostream>
using namespace std;

int fibonacci(int n) {
	static int mem[41] = {};
	if (mem[n] > 0) return mem[n];
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	return mem[n] = fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
	int t, n;
	cin >> n;

	for (int i = 0; i < t; ++i) {
		cin >> n;
		if (n == 0) cout << "1 0\n";
		else cout << fibonacci(n - 1) << ' ' << fibonacci(n) << '\n';
	}
}