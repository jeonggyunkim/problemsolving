#include <iostream>
#define INF 1987654321
using namespace std;

char arr[10][51];
char name[51];

int main() {
	int n, m;
	cin >> n >> m;

	int count = -1;
	int ans;

	for (int i = 0; i < n; ++i) cin >> name >> arr[i];

	for (int i = 0; i < (1 << n); ++i) {
		bool go[51] = {};
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				for (int k = 0; k < m; ++k) {
					if (arr[j][k] == 'Y') go[k] = 1;
				}
			}
		}

		int cnt = 0;
		for (int j = 0; j < m; ++j) {
			if (go[j]) cnt++;
		}

		if (count < cnt) {
			count = cnt;
			ans = __builtin_popcount(i);
		}
		else if (count == cnt) {
			ans = min(ans, __builtin_popcount(i));
		}
	}

	if (count == 0) cout << -1;
	else cout << ans;
}