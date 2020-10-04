#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int t, xo = 0;
	while (n--) {
		cin >> t;
		xo ^= t;
	}
	if (xo) cout << "koosaga";
	else cout << "cubelover";
}