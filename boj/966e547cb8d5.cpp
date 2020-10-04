#include <iostream>
using namespace std;

int mod;

long long pow(long long a, long long b) {
	if (b == 1) return a % mod;
	if (b & 1) {
		return (a * pow(a, b - 1)) % mod;
	}
	else {
		a = (a * a) % mod;
		return pow(a, b / 2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b >> mod;

	cout << pow(a, b);
}