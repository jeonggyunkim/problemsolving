#include <iostream>
using namespace std;

long long mem[41][41];

long long c(int n, int k) {
	if (mem[n][k]) return mem[n][k];
	if (n == 0 || k == 0 || n == k) return mem[n][k] = 1;
	return mem[n][k] = c(n - 1, k - 1) + c(n - 1, k);
}

int main() {
	cout << c(40, 20) << endl;
}