#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		cin >> arr[i];
	}

	bool right = 1, up = 1;
	int u = 1, d = 1, r = 1, l = 1;
	bool ver = 1;
	for (int i = 0; i < n; ++i) {
		if (ver) {
			if (right) {
				cout << r;
				l += r;
				r = 1;
				up = (arr[i] == 1);
			}
			else {
				cout << l;
				r += l;
				l = 1;
				up = (arr[i] == -1);
			}
		}
		else {
			if (up) {
				cout << u;
				d += u;
				u = 1;
				right = (arr[i] == -1);
			}
			else {
				cout << d;
				u += d;
				d = 1;
				right = (arr[i] == 1);
			}
		}
		ver = !ver;
		cout << '\n';
	}
}