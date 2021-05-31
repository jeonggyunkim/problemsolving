#include <iostream>
#include <memory.h>
#define N 500
#define INF 987654321
using namespace std;

int n;
int w[N][N];
bool merged[N];
bool A[N];
int q[N];

int update_weight(int v) { // update value and return max vertex
	int qmax = -1, maxind;
	for (int i = 0; i < n; ++i) {
		if (!merged[i] && !A[i]) {
			q[i] += w[v][i];
			if (q[i] > qmax) {
				qmax = q[i];
				maxind = i;
			}
		}
	}
	return maxind;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		memset(w, 0, sizeof(w));

		int m;
		cin >> n >> m;

		int a, b, c;
		while (m--) {
			cin >> a >> b >> c;
			a--; b--;
			w[a][b] += c;
			w[b][a] += c;
		}

		int ans = INF;
		memset(merged, 0, sizeof(merged));
		for (int epoch = 1; epoch < n; ++epoch) {
			memset(A, 0, sizeof(A));
			memset(q, 0, sizeof(q));

			int next, prev;
			for (int i = 0; i < n; ++i) {
				if (!merged[i]) {
					A[i] = 1;
					prev = i;
					next = update_weight(i);
					break;
				}
			}

			for (int i = 0; i < n - epoch - 1; ++i) {
				prev = next;
				A[next] = 1;
				next = update_weight(next);
			}

			ans = min(ans, q[next]);
			merged[next] = 1;
			for (int i = 0; i < n; ++i) {
				w[i][prev] += w[i][next];
				w[prev][i] += w[next][i];
			}
		}
		cout << ans << '\n';
	}
}