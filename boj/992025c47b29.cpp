#include <iostream>
#include <vector>
using namespace std;

char arr[400][400];

void star(int a, int n) {
	int nn = 4 * n - 3;
	for (int i = 0; i < nn; ++i) {
		arr[a + i][a] = '*';
		arr[a + i][a + nn - 1] = '*';
		arr[a][a + i] = '*';
		arr[a + nn - 1][a + i] = '*';
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < 4 * n - 3; ++i) {
		for (int j = 0; j < 4 * n - 3; ++j) {
			arr[i][j] = ' ';
		}
		arr[i][4 * n - 3] = 0;
	}

	for (int i = 0; i < n; i++) {
		star(2 * i, n - i);
	}

	for (int i = 0; i < 4 * n - 3; ++i) {
		cout << arr[i] << '\n';
	}
}