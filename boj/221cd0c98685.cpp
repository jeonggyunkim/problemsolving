#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long> x(n + 1), y(n + 1);
	vector<long long> sumx(n + 1), sumy(n + 1);
	vector<int> xind(n + 1), yind(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}

	vector<ii> t(n);
	for (int i = 0; i < n; ++i) t[i] = ii(x[i + 1], i + 1);
	sort(t.begin(), t.end());

	for (int i = 0; i < n; ++i) {
		sumx[i + 1] = sumx[i] + t[i].first;
		xind[t[i].second] = i + 1;
	}

	for (int i = 0; i < n; ++i) t[i] = ii(y[i + 1], i + 1);
	sort(t.begin(), t.end());

	for (int i = 0; i < n; ++i) {
		sumy[i + 1] = sumy[i] + t[i].first;
		yind[t[i].second] = i + 1;
	}

	long long mind = 1LL << 62, d;
	int ans;
	for (int i = 1; i <= n; ++i) {
		d = x[i] * (xind[i]) - sumx[xind[i]];
		d += sumx[n] - sumx[xind[i]] - x[i] * (n - xind[i]);
		d += y[i] * (yind[i]) - sumy[yind[i]];;
		d += sumy[n] - sumy[yind[i]] - y[i] * (n - yind[i]);
		if (d < mind) {
			mind = d;
			ans = i;
		}
	}

	cout << ans;
}