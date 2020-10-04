#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	int a, b;
	while (tc--) {
		cin >> a >> b;
		cout << a * b / __gcd(a, b) << '\n';
	}
}