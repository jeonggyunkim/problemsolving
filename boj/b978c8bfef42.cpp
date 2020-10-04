#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	char str[2010][2010];
	for (int i = 0; i < n; ++i) cin >> str[i];

	int ans = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			bool cng = 1;
			if (i != 0 && str[i][j] != str[i - 1][j]) cng = 0;
			if (i != n - 1 && str[i][j] != str[i + 1][j]) cng = 0;
			if (j != 0 && str[i][j] != str[i][j - 1]) cng = 0;
			if (j != m - 1 && str[i][j] != str[i][j + 1]) cng = 0;
			if (cng) {
				(ans *= 2) %= MOD;
			}
		}
	}

	cout << ans;
}