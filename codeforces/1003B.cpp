#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, x;
	cin >> a >> b >> x;

	int pos = a < b ? 1 : 0;
	vector<int> ans(a + b);
	int i = 0;
	while (x != 1) {
		ans[i++] = pos;
		if (pos) b--;
		else a--;
		pos = 1 - pos;
		x--;
	}
	if (pos) while (b--) ans[i++] = pos;
	else while (a--) ans[i++] = pos;
	pos = 1 - pos;
	if (pos) while (b--) ans[i++] = pos;
	else while (a--) ans[i++] = pos;

	for (int i = 0; i < ans.size(); ++i) cout << ans[i];
}