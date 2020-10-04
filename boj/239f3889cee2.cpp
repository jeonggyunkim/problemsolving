#include <iostream>
using namespace std;

int main() {
	int n, x = 0, t;
	cin >> n;

	while (n--) {
		cin >> t;
		x ^= t;
	}

	if (x) cout << "koosaga";
	else cout << "cubelover";
}