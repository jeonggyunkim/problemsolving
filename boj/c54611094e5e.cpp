#include <iostream>
using namespace std;

int base[2][2] = {{1, 1}, {1, 0}};
int p[2][2], temp[2][2];

void cp(int a[2][2], int b[2][2]) {
	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < 2; ++j) a[i][j] = b[i][j];
}

void mul(int a[2][2], int b[2][2], int c[2][2]) {
	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < 2; ++j) {
		c[i][j] = 0;
		for (int k = 0; k < 2; ++k) c[i][j] += a[i][k] * b[k][j];
		c[i][j] %= 10000;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	while (cin >> t, t != -1) {
		cp(p, base);
		int ans[2][2] = {{1, 0}, {0, 1}};
		while (t) {
			if (t & 1) {
				mul(ans, p, temp);
				cp(ans, temp);
			}
			t /= 2;
			mul(p, p, temp);
			cp(p, temp);
		}
		cout << ans[0][1] << '\n';
	}
}