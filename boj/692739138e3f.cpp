#include <iostream>
using namespace std;

char name[110], hj[5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	int sum = 0;
	double psum = 0, now;
	for (int i = 0; i < n; ++i) {
		cin >> name >> t >> hj;
		if (hj[0] == 'F') now = 0;
		else {
			now = 4 + 'A' - hj[0];
			if (hj[1] == '+') now += 0.3;
			else if (hj[1] == '-') now -= 0.3;
		}
		
		sum += t;
		psum += now * t;
	}
	psum += 1e-7;
	cout.precision(2);
	cout << fixed;
	cout << psum / sum;
}