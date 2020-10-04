#include <iostream>
using namespace std;

int main() {
	int c[101][101];
	int cnt = 0;

	for (int i = 1; i <= 100; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || i == j) c[i][j] = 1;
			else {
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			}
			if (c[i][j] >= 1000000) {
				c[i][j] = 1000000;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}