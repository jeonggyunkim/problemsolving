#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int res, t;
	char op;
	cin >> res;
	while (cin >> op, op != '=') {
		cin >> t;
		if (op == '+') res += t;
		else if (op == '-') res -= t;
		else if (op == '*') res *= t;
		else if (op == '/') res /= t;
	}
	cout << res;
}