#include <iostream>
#define INF 987654321
using namespace std;

int arr[200];
int dist[200][200]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i) cin >> arr[i];

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> dist[i][j];
				if (dist[i][j] == -1) dist[i][j] = INF;
			}
		}

		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		long long ans = 0;
		for (int i = 1; i < n; ++i) {
			ans += dist[arr[i - 1]][arr[i]];
		}
		ans += dist[arr[n - 1]][arr[0]];
		if (ans >= INF) cout << "impossible\n";
		else cout << ans << '\n';
	}
}