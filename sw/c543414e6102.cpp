#include <iostream>
using namespace std;

int main() {
	long long fib[95];
	fib[1] = fib[0] = 1;
	for (int i = 2; i < 95; ++i) fib[i] = fib[i - 1] + fib[i - 2];

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int k;
		cin >> k;
		cout << '#' << test << ' ' << fib[k + 1] << ' ' << fib[k] << '\n';
	}
}
