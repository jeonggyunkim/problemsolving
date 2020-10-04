#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, t;
	cin >> n >> m;
	vector<vector<int>> moim(m);
	vector<bool> final(n, 0);
	vector<int> before(n, -1);

	for (int i = 0; i < m; ++i) {
		cin >> k;
		moim[i].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> moim[i][j];
			moim[i][j]--;
		}
	}

	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t) final[i] = 1;
		else before[i] = m - 1;
	}

	for (int i = m - 1; i >= 0; --i) {
		bool notinf = 0;
		for (int u: moim[i]) {
			if (before[u] >= i) notinf = 1;
		}
		if (notinf) {
			for (int u: moim[i]) before[u] = max(before[u], i);
		}
	}

	vector<bool> contam(n, 0);
	for (int i = 0; i < n; ++i) {
		if (before[i] == -1) contam[i] = 1;
	}

	for (int i = 0; i < m; ++i) {
		bool inf = 0;
		for (int u: moim[i]) {
			if (contam[u]) inf = 1;
		}
		if (inf) {
			for (int u: moim[i]) contam[u] = 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (final[i] != contam[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		if (before[i] == -1) cout << "1 ";
		else cout << "0 ";
	}
}