#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int t, sum = 0, m = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		sum += t;
		m = max(m ,t);
	}

	cout.precision(7);
	cout << (double)sum / (m * n) * 100;
}