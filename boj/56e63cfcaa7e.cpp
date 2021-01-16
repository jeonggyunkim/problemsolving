#include <iostream>
#include <vector>
#define N 1000001
using namespace std;

typedef pair<int, int> ii;

vector<ii> factorize(unsigned int n) {
	vector<ii> ret;
	if (n <= 1) return ret;
	if (n % 2 == 0) {
		int cnt = 0;
		while (n % 2 == 0) {
			cnt++;
			n /= 2;
		}
		ret.push_back(ii(2, cnt));
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			ret.push_back(ii(i, cnt));
		}
	}
	if (n != 1) ret.push_back(ii(n, 1));
	return ret;
}

int cnt[N + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<vector<ii>> div(N + 1);
	for (int i = 2; i <= N; ++i) {
		div[i] = factorize(i);
	}

	int odd = 0;
	int n, t;
	cin >> n;

	while (n--) {
		cin >> t;
		for (ii u: div[t]) {
			if (cnt[u.first] & 1) odd--;
			cnt[u.first] += u.second;
			if (cnt[u.first] & 1) odd++;
		}
		if (odd) cout << "NE\n";
		else cout << "DA\n";
	}
}