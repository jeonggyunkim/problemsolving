#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n = 600851475143;
	long long i = 3;
	while (i * i <= n) {
		if (n % i == 0) {
			n /= i;
		}
		i += 2;
	}
	cout << n << endl;
}