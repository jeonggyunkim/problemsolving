#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;
	set<int> s;

	while (n--) {
		cin >> t;
		if (t != 0) s.insert(t);
	}
	cout << s.size();
}