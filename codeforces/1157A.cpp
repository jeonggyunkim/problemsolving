#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	set<int> s;
	while (1) {
		s.insert(n);
		n++;
		while (n % 10 == 0) n /= 10;

		if (s.count(n)) break;
	}

	cout << s.size();
}
