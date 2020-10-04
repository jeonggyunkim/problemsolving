#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	cout << fixed;
	cout.precision(1);

	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		int s1 = 0;
		double s2 = 0;

		int ss1;
		double ss2;
		for (int j = 0; j < m; ++j) {
			cin >> ss1 >> ss2;
			s1 += ss1;
			s2 += ss2 * ss1;
		}
		s2 /= s1;
		cout << s1 << " " << s2 << endl;
	}

	return 0;
}