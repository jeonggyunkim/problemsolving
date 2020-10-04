#include <iostream>
using namespace std;

int main() {
	int L, P, T;
	cin >> L >> P;

	for (int i = 0; i < 5; ++i) {
		cin >> T;
		cout << T - L * P << ' ';
	}
	cout << endl;
}