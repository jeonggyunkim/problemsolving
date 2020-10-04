#include <iostream>
#include <memory.h>
using namespace std;

int cnt, a[100001], v[100001];

int dfs(int n) {
	if (v[n] == 1) return 0;
	else if (v[n] == 2) return n;

	v[n] = 2;
	int ret = dfs(a[n]);
	if (ret) {
		cnt++;
		v[n] = 1;
		if (n == ret) return 0;
		else return ret;
	}
	else {
		v[n] = 1;
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		cnt = 0;
		memset(v, 0, sizeof(v));
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= n; ++i) if (v[i] == 0) dfs(i);
		cout << n - cnt << '\n';
	}
}