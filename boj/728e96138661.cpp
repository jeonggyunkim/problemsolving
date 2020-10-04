#include <iostream>
#include <vector>
using namespace std;

int r, c;
bool check[5] = {1, 0, 0, 1, 0};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool table[20][12177];
bool mask[20][12177];

int get(int i, int j, int d) {
	if (i < 0 || i >= r || j < 0 || j >= c || mask[i][j] || table[i][j] != check[d]) return 0;
	if (d == 4) return 1;
	mask[i][j] = 1;
	int ret = 0;
	for (int k = 0; k < 4; ++k) {
		ret += get(i + dir[k][0], j + dir[k][1], d + 1);
	}
	mask[i][j] = 0;
	return ret;
}

int main() {
	cin >> r >> c;

	long long ans = 0;
	if (r > 15) {
		int rr = (r - 15) / 5;
		r = 15 + r % 5;
		for (int i = 0; i < r * c; ++i) {
			if (i % 5 == 0 || i % 5 == 3) table[i / c][i % c] = 1;
			else table[i / c][i % c] == 0;
		}
		vector<int> sum(r, 0);
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
			int t = get(i, j, 0);
			ans += t;
			sum[i] += t;
		}
		long long tt = 0;
		for (int i = 5; i < 10; ++i) tt += sum[i];
		ans += rr * tt;
	}
	else {
		for (int i = 0; i < r * c; ++i) {
			if (i % 5 == 0 || i % 5 == 3) table[i / c][i % c] = 1;
			else table[i / c][i % c] == 0;
		}
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
			ans += get(i, j, 0);
		}
	}
	cout << ans;
}
