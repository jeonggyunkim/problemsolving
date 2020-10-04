#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	long long canmake[21] = {};
	cin >> t;
	canmake[t] = 1;

	for (int i = 1; i < n - 1; ++i) {
		long long temp[21] = {};
		cin >> t;
		for (int j = 0; j < 21; ++j) {
			if (0 <= j - t && j - t <= 20) temp[j - t] += canmake[j];
			if (0 <= j + t && j + t <= 20) temp[j + t] += canmake[j];
		}
		for (int j = 0; j < 21; ++j) canmake[j] = temp[j];
	}
	cin >> t;
	cout << canmake[t];
}