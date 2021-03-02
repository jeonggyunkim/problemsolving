#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	while (cin >> a >> b >> c) {
		cout << max(c - b, b - a) - 1 << '\n';
	}
}