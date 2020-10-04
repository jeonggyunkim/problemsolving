#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int floor[300][2];
	int t;
	cin >> t;
	floor[0][0] = t; floor[0][1] = t;
	if (n == 1) {
		cout << t;
		return 0;
	}
	cin >> t;
	floor[1][0] = t; floor[1][1] = floor[0][0] + t;

	for (int i = 2; i < n; ++i) {
		cin >> t;
		floor[i][0] = max(floor[i - 2][0], floor[i - 2][1]) + t;
		floor[i][1] = floor[i - 1][0] + t;
	}
	cout << max(floor[n - 1][0], floor[n - 1][1]);
}