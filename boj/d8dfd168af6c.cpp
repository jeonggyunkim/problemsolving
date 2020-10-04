#include <iostream>
#include <algorithm>
using namespace std;

int num[100010];
int l[200010], r[200010];
bool sym[200010];
int cnt = 0;

void dfs(int i, bool neg) {
	if (!l[i]) {
		if (neg) cnt++;
		return;
	}
	dfs(l[i], neg);
	if (sym[i]) dfs(r[i], !neg);
	else dfs(r[i], neg);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> num[i];

	char c;
	for (int i = n + 1; i <= 2 * n - 1; ++i) {
		cin >> c >> l[i] >> r[i];
		if (c == '-') sym[i] = 1;
	}

	dfs(2 * n - 1, 0);

	int ans = 0;
	sort(num, num + n);
	for (int i = 0; i < cnt; ++i) ans -= num[i];
	for (int i = cnt; i < n; ++i) ans += num[i];
	cout << ans;
}