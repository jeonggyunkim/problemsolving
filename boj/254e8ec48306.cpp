#include <iostream>
using namespace std;

int time[20][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, sum = 0;
	cin >> n;

	int cnt = n * n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> time[i][j];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			int find = 0;
			for (int k = 0; k < n; ++k) {
				if (i == k || j == k) continue;
				if (time[i][k] + time[k][j] == time[i][j]) {
					find = 1;
					break;
				}
				if (time[i][k] + time[k][j] < time[i][j]) {
					cout << -1;
					return 0;
				}
			}
			if (!find) {
				sum += time[i][j];
			}
		}
	}

	cout << sum / 2;
}