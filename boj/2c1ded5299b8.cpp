#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long ll;

int n;
ll matrix[100][20][20];
ll Tprod[20][20];

void matmul(ll a[20][20], ll b[20][20]) {
	ll ret[20][20] = {};
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < n; ++k) {
			ll t = a[i][k];
			for (int j = 0; j < n; ++j) {
				(ret[i][j] += t * b[k][j]) %= MOD;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = ret[i][j];
		}
	}
}

void matrixPower(ll a[20][20], int p) {
	if (p == 0) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = (i == j);
			}
		}
		return;
	}
	if (p == 1) return;
	ll temp[20][20];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			temp[i][j] = a[i][j];
		}
	}
	matmul(a, a);
	matrixPower(a, p / 2);
	if (p & 1) matmul(a, temp);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	matmul(matrix[0], matrix[1]);

	int t, d;
	cin >> t >> n >> d;

	for (int i = 0; i < t; ++i) {
		int m;
		cin >> m;
		while (m--) {
			int a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			matrix[i][a][b] = c;
		}
	}


	for (int i = 0; i < n; ++i) Tprod[i][i] = 1;

	for (int i = 0; i < t; ++i) matmul(Tprod, matrix[i]);

	matrixPower(Tprod, d / t);

	for (int i = 0; i < d % t; ++i) matmul(Tprod, matrix[i]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << Tprod[i][j] << ' ';
		}
		cout << '\n';
	}
}