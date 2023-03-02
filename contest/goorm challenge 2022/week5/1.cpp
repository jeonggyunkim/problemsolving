#include <iostream>
#include <set>
using namespace std;

typedef pair<int, int> ii;

int arr[100][100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, ans = 0;
	cin >> n >> m;

	set<ii> st;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				st.insert({i, j});
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == 1) {
				for (int k = -m; k <= m; ++k) {
					auto it = st.lower_bound({i + k, j - (m - abs(k))});
					if (it != st.end() && it->first == i + k && it->second >= j - (m - abs(k)) && it->second <= j + (m - abs(k))) {
						ans++;
						break;
					}
				}
			}
		}
	}
	cout << ans;
}