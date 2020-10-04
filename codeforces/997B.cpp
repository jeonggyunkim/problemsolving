#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> base = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
	int n;
	cin >> n;

	if (n < base.size()) cout << base[n];
	else cout << base.back() + 49LL * (n + 1 - base.size());
}