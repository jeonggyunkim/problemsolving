#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int ans[64] = {}, now = 1;

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n;
		cin >> n;
		
		cout << "Case #" << test << '\n';
		while (ans[n] == 0) {
			int i = now;
			int cnt = 0;
			while (i != 1) {
				if (i % 2 == 0) i /= 2;
				else i = 3 * i + 1;
				cnt++;
			}
			if (cnt < 64 && ans[cnt] == 0) ans[cnt] = now;
			now++;
		}
		cout << ans[n] << ' ';
		cout << (1ull << n) << '\n';
	}
}