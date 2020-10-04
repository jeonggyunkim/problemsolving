#include <iostream>
#define N 15010
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	bool mask[N] = {};
	cin >> t;
	mask[0] = 1;
	mask[t] = 1;

	for (int i = 1; i < n; ++i) {
		bool temp[N];
		for (int j = 0; j < N; ++j) {
			temp[j] = mask[j];
		}
		cin >> t;
		mask[t] = 1;
		for (int j = t; j >= 0; --j) {
			if (temp[j]) mask[t - j] = 1;
		}
		for (int j = 0; j < N; ++j) {
			if (temp[j]) {
				if (j - t >= 0) mask[j - t] = 1;
				if (t + j < N) mask[t + j] = 1;
			}
		}
	}

	cin >> n;
	while (n--) {
		cin >> t;
		if (t < N && mask[t]) cout << 'Y';
		else cout << 'N';
		cout << ' ';
	}
}