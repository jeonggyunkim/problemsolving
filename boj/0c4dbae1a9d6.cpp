#include <iostream>
#define INF 987654321
using namespace std;

int d[2][201][201];
int pi[2][201][201] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			d[0][i][j] = INF;
		}
		d[0][i][i] = 0;
	}
	int p, q, r;
	for (int i = 0; i < m; ++i) {
		cin >> p >> q >> r;
		d[0][p][q] = d[0][q][p] = r;
		pi[0][p][q] = q;
		pi[0][q][p] = p;
	}

	for (int k = 1; k <= n; ++k) {
		int loc = k % 2;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (d[1 - loc][i][j] > d[1 - loc][i][k] + d[1 - loc][k][j] && d[1 - loc][i][k] + d[1 - loc][k][j] < 0x7ffffff) {
					d[loc][i][j] = d[1 - loc][i][k] + d[1 - loc][k][j];
					pi[loc][i][j] = pi[1 - loc][i][k];
				}
				else {
					d[loc][i][j] = d[1 - loc][i][j];
					pi[loc][i][j] = pi[1 - loc][i][j];
				}
			}
		}
	}

	int loc = n % 2;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (pi[loc][i][j] == 0) {
				cout << "- ";
			}
			else {
				cout << pi[loc][i][j] << ' ';
			}
		}
		cout << '\n';
	}
	cout << '\n';
}