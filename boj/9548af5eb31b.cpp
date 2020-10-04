#include <iostream>
using namespace std;

int main() {
	int n, t;
	cin >> n;

	while (n--) {
		cin >> t;
		while (t--) cout << '=';
		cout << '\n';
	}
}