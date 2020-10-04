#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[10];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		arr[i]--;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (arr[i] == arr[j]) {
				cout << "NO";
				return 0;
			}
		}
	}

	int board[3][3] = {};
	board[arr[0] / 3][arr[0] % 3] = 1;
	int dig[4][2] = {{0, 8}, {8, 0}, {2, 6}, {6, 2}};

	for (int i = 1; i < n; ++i) {
		if (arr[i] / 3 == arr[i - 1] / 3 && abs(arr[i] % 3 - arr[i - 1] % 3) == 2) {
			if (board[arr[i] / 3][1] == 0) {
				cout << "NO";
				return 0;
			}
		}
		if (arr[i] % 3 == arr[i - 1] % 3 && abs(arr[i] / 3 - arr[i - 1] / 3) == 2) {
			if (board[1][arr[i] % 3] == 0) {
				cout << "NO";
				return 0;
			}
		}
		for (int k = 0; k < 4; ++k) {
			if (arr[i] == dig[k][0] && arr[i - 1] == dig[k][1]) {
				if (board[1][1] == 0) {
					cout << "NO";
					return 0;
				}
			}
		}
		board[arr[i] / 3][arr[i] % 3] = 1;
	}
	cout << "YES";
}