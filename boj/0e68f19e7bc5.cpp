#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;
		int count = 0;
		for (int j = 0; j < n; ++j) {
			int cx, cy, r, d;
			bool in1;
			bool in2;
			cin >> cx >> cy >> r;
			d = (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1);
			in1 = d > r * r ? false : true;
			d = (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2);
			in2 = d > r * r ? false : true;
			if (in1 != in2) {
				count++;
			}
		}
		cout << count << '\n';
	}
}