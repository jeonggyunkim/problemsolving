#include <iostream>
using namespace std;

int n;
int pa[1000000];

long long num(int l) {
	long long ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += pa[i] / l;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	long long m;
	cin >> m;

	int low = 1, high = -1;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> pa[i];
		high = max(high, pa[i] + 1);
		ans += pa[i];
	}

	while (high - low > 1) {
		int mid = (high + low) / 2;
		long long r = num(mid);
		if (r >= m) low = mid;
		else high = mid;
	}

	cout << ans - low * m;
}