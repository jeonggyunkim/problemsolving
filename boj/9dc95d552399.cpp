#include <iostream>
using namespace std;

int main() {
	int arr[101][101] = {};

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < b; k++) {
				arr[y + k][x + j] = i;
			}
		}
	}
	int* count = new int[n];
	for (int i = 0; i < n; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j]) {
				count[arr[i][j] - 1] += 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << count[i] << endl;
	}

	return 0;
}
