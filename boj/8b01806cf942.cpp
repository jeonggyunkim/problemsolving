#include <iostream>
using namespace std;

int N;

void matmul(int s[5][5], int a[5][5]) {
	int v[5][5];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int n = 0;
			for (int k = 0; k < N; ++k) n += s[i][k] * a[k][j];
			v[i][j] = n % 1000;
		}
	}
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) s[i][j] = v[i][j];
}

void exp(int a[5][5], long long n) {
	if (n == 1) return;
	if (n % 2 == 0) {
		matmul(a, a);
		exp(a, n / 2);
	}
	else {
		int r[5][5];
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) r[i][j] = a[i][j];
		exp(a, --n);
		matmul(a, r);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long B;
	cin >> N >> B;

	int a[5][5];

	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
		cin >> a[i][j];
		a[i][j] %= 1000;
	}

	exp(a, B);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cout << a[i][j] << ' ';
		cout << '\n';
	}
}