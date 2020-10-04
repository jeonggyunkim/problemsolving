#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	int ind = 2, n = 3;
	while (ind != 10001) {
		n += 2;
		if (isPrime(n)) ind++;
	}
	cout << n << endl;
}
