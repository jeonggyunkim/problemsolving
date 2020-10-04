#include <iostream>
#include <string>
using namespace std;

bool ispel(int n) {
	string s;
	while (n) {
		s.push_back(n % 10);
		n /= 10;
	}
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - 1 - i]) return 0;
	}
	return 1;
}

bool isPrime(int n) {
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	while (true) {
		if (ispel(n) && isPrime(n)) {
			cout << n;
			return 0;
		}
		n++;
	}
}