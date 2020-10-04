#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		cout << a + b << '\n';
	}
}