#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		double d, a, b, f;
		cin >> n >> d >> a >> b >> f;
		cout.precision(10);
		cout << n << ' ' << d / (a + b) * f << '\n';
	}
}