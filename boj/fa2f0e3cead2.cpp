#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	while (cin >> a >> b, a || b) {
		if (a > b) cout << "Yes\n";
		else cout << "No\n";
	}
}