#include <iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		double t;
		cin >> t;
		cout.precision(2);
		cout << fixed;
		cout << '$' << t * 0.8 << '\n';
	}
}