#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);

	if (a == 5 && b == 5 && c == 7) cout << "YES";
	else cout << "NO";
}
