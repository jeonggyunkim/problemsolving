#include <iostream>
using namespace std;


long long fib(int n) {
	static long long mem[100] = {};
	if (mem[n] > 0) {
		return mem[n];
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	return mem[n] = fib(n - 2) + fib(n - 1);
}

int main() {
	int n;
	cin >> n;

	cout << fib(n) << endl;

	return 0;
}