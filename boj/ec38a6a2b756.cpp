#include <iostream>
using namespace std;

char ori[10][21];
char rev[10][21];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> ori[i];
	for (int i = 0; i < n; ++i) cin >> rev[i];

	bool cor = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2 * m; ++j) {
			if (rev[i][j] != ori[i][j / 2]) cor = 0;
		}
	}
	if (cor) cout << "Eyfa";
	else cout << "Not Eyfa";
}