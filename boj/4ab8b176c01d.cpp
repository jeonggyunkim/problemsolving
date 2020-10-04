#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a < 2 || (a == 2 && b < 18)) cout << "Before";
	else if (a == 2 && b == 18) cout << "Special";
	else cout << "After";
}