#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n -= 2;

	for (int i = 0; i < n; ++i) cout << 'A';
	cout << "Aa\n";
	for (int i = 0; i < n; ++i) cout << 'A';
	cout << "BB";
}