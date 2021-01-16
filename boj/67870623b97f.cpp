#include <iostream>
using namespace std;

double prob[1001][1001];

int main() {
	int n;
	cin >> n;

	int sum = 0, t, ini;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		sum += t;
		if (i == 0) ini = t;
	}

	int J, C;
	cin >> J >> C;

	prob[0][0] = 1;

	for (int i = 0; i < C; ++i) {
		for (int j = 0; j <= i; ++j) {
			prob[i + 1][j] += prob[i][j] * (sum - ini - J * j) / sum;
			prob[i + 1][j + 1] += prob[i][j] * (ini + J * j) / sum;
		}
		sum += J;
	}
	double ans = 0;
	for (int i = 0; i <= C; ++i) {
		ans += prob[C][i] * (ini + J * i);
	}
	cout.precision(20);
	cout << fixed;
	cout << ans;
}