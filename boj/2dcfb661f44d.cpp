#include <iostream>
using namespace std;

int pre[1000], in[1000], ind[1000];

void post(int a, int b, int c, int d) {
	if (a >= b) return;

	int t = ind[pre[a]];
	post(a + 1, a + 1 + t - c, c, t);
	post(a + 1 + t - c, b, t + 1, d);
	cout << pre[a] + 1 << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i) {
			cin >> pre[i];
			pre[i]--;
		}
		for (int i = 0; i < n; ++i) {
			cin >> in[i];
			in[i]--;
			ind[in[i]] = i;
		}

		post(0, n, 0, n);
		cout << '\n';
	}
}