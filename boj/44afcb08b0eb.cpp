#include <iostream>
#include <memory.h>
#define MOD 1000003
using namespace std;

long long mat[50][50], result[50][50], temp[50][50];

void matmul(int sz, int t) {
	for (int i = 0; i < sz; ++i) {
		result[i][i] = 1;
	}

	while (t) {
		if (t & 1) {
			for (int i = 0; i < sz; ++i) {
				for (int j = 0; j < sz; ++j) {
					temp[i][j] = 0;
					for (int k = 0; k < sz; ++k) {
						temp[i][j] += result[i][k] * mat[k][j];
						temp[i][j] %= MOD;
					}
				}
			}

			memcpy(result, temp, sizeof(temp));
		}
		for (int i = 0; i < sz; ++i) {
			for (int j = 0; j < sz; ++j) {
				temp[i][j] = 0;
				for (int k = 0; k < sz; ++k) {
					temp[i][j] += mat[i][k] * mat[k][j];
					temp[i][j] %= MOD;
				}
			}
		}

		memcpy(mat, temp, sizeof(temp));
		t /= 2;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s, e, t;
	cin >> n >> s >> e >> t;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		for (int j = 0; j < n; ++j) {
			if (s[j] != '0') {
				mat[5 * j][i * 5 + s[j] - '1'] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < 5; ++j) {
			mat[5 * i + j][5 * i + j - 1] = 1;
		}
	}

	matmul(5 * n, t);
	cout << result[5 * (e - 1)][(s - 1) * 5];
}