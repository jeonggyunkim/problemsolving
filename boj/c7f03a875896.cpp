#include <iostream>
using namespace std;

int arr[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		bool out[100] = {};
		int ind = 0, mv;
		for (int i = 0; i < n; ++i) {
			while (out[ind]) ind = (ind + 1) % n;
			mv = arr[ind];
			int jnd = ind;
			for (int j = 1; j < n; ++j) {
				jnd = (jnd + 1) % n;
				if (!out[jnd] && arr[jnd] > mv) {
					ind = jnd;
					mv = arr[jnd];
				}
			}
			if (ind == m) {
				cout << i + 1 << '\n';
				break;
			}
			out[ind] = 1;
		}
	}
}