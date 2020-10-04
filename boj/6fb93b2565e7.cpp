#include <iostream>
using namespace std;

void hanoi(int a, int b, int c, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	hanoi(a, c, b, n - 1);
	cout << a << ' ' << b << '\n';
	hanoi(c, b, a, n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int move = 1;
	for (int i = 0; i < n; ++i) {
		move *= 2;
	}
	move--;
	cout << move << '\n';

	hanoi(1, 3, 2, n);
}