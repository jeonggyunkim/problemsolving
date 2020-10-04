#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	cout << n << '\n';
	cout << "1 ";
	if (n > 1) cout << "2 ";
	for (int i = 2; i < n - 1; ++i) cout << i + 1 << ' ';
	if (n > 2) cout << 997;
}