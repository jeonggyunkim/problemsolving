#include <iostream>
using namespace std;

char arr[400][400];

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		printf("*");
		return 0;
	}

	int a = 4 * n - 3;
	int b = 4 * n - 1;

	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			arr[i][j] = ' ';
		}
		arr[i][a] = 0;
	}

	int x = a - 1;
	int y = 0;

	for (int i = n - 1; i > 0; --i) {
		for (int j = 0; j < 4 * i; ++j) {
			arr[y][x] = '*';
			--x;
		}
		for (int j = 0; j < 4 * i + 2; ++j) {
			arr[y][x] = '*';
			++y;
		}
		for (int j = 0; j < 4 * i; ++j) {
			arr[y][x] = '*';
			++x;
		}
		for (int j = 0; j < 4 * i; ++j) {
			arr[y][x] = '*';
			--y;
		}
		for (int j = 0; j < 2; ++j) {
			arr[y][x] = '*';
			--x;
		}
	}
	for (int j = 0; j < 3; ++j) {
		arr[y][x] = '*';
		++y;
	}

	for (int i = 0; i < b; ++i) {
		int star = 0;
		for (int j = 0; j < a; ++j) {
			if (arr[i][j] == '*') {
				star = j;
			}
		}
		arr[i][star + 1] = 0;
		cout << arr[i] << '\n';
	}
}