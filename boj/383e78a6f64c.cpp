#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q, t;
	cin >> q;

	while (q--) {
		cin >> t;
		cout << !(t & (t - 1)) << '\n';
	}
}