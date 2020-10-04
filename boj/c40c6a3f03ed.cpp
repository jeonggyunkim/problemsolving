#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	cout << __gcd(m, n) << '\n';
	cout << m * n / __gcd(m, n);
}