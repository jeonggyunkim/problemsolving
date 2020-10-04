#include <iostream>
using namespace std;

int main() {
	int list[1035];
	int A, B;
	cin >> A >> B;

	int i = 0;
	for (int n = 1; n <= 45; ++n) {
		for (int j = 0; j < n; ++j) {
			list[i++] = n;
		}
	}

	int sum = 0;
	for (int i = A - 1; i < B; ++i) {
		sum += list[i];
	}

	cout << sum << endl;

	return 0;
}