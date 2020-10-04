#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a;
	cin >> a;

	int ans = 0;
	vector<int> prev;
	for (int i = 0; i < a.size(); ++i) {
		if ((a[i] - '0') % 3 == 0) {
			ans++;
			prev.clear();
		}
		else {
			bool brk = 0;
			for (int j = 0; j < prev.size(); ++j) {
				if ((prev[j] + a[i] - '0') % 3 == 0) {
					ans++;
					prev.clear();
					brk = 1;
					break;
				}
				else prev[j] += a[i] - '0';
			}
			if (!brk) prev.push_back(a[i] - '0');
		}
	}
	cout << ans;
}