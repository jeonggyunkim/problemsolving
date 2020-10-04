#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;

	if (n % 5 == 0 || n % 5 == 2) cout << "CY";
	else cout << "SK";
}