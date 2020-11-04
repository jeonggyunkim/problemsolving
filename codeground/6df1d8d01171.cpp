#include <bits/stdc++.h>
using namespace std;

int tree[400010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	for (int test = 1; test <= tc; ++test) {
		memset(tree, 0, sizeof(tree));
		int n, s = 200003, cut = -1, t;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> t;
			tree[s + t]++;
			cut = max(cut, s + t);
		}
		
		for (int i = cut; i >= s; --i) tree[i] += tree[i + 1];
		
		long long ans = 0;
		while (n--) {
			cin >> t;
			if (s + t < cut) {
				for (int i = s + t; i <= cut; ++i) ans += (long long)(i - s - t) * (tree[i] - tree[i + 1]);
				cut = s + t;
				tree[cut + 1] = 0;
			}
			s--;
			tree[s] = tree[s + 1];
		}
		
		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}