#include <iostream>
using namespace std;

int main() {
	int fib[51];
	fib[0] = fib[1] = 1;
	for (int i = 2; i <= 50; ++i) {
		fib[i] = (1 + fib[i - 1] + fib[i - 2]) % 1000000007;
	}

	int n;
	cin >> n;
	cout << fib[n];
 }