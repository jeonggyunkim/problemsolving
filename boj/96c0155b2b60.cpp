#include <iostream>
using namespace std;

int main() {
	int arr[101][101] = {};

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				arr[x + j][y + k] = i;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j]) {
				count += 1;
			}
		}
	}

	cout << count << endl;

	return 0;
}
