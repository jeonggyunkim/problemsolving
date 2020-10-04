#include <iostream>
using namespace std;

int main() {
	int remain = 0;
	int n, a, b;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		remain += b % a;
	}

	cout << remain << endl;

	return 0;
}