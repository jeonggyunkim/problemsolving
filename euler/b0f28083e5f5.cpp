#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n = 1;
	for (long long i = 1; i <= 20; ++i) {
		n = n * i / __gcd(n, i);
	}
	cout << n << endl;
}