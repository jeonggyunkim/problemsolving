#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;

	if (n % 7 == 2 || n % 7 == 0) cout << "CY";
	else cout << "SK";
}