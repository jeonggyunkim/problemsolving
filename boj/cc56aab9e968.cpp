#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[20];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	long long a = 0, b = 1;
	for (int i = n - 1; i >= 0; --i) {
		a += arr[i] * b;
		swap(a, b);
		long long d =__gcd(a, b);
		a /= d; b /= d;
	}
	a = b - a;

	cout << a << ' ' << b;
}