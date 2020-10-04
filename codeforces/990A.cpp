#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, m, a, b;
	cin >> n >> m >> a >> b;

	long long l = n - n % m;
	long long h = l + m;

	cout << min((n - l) * b, (h - n) * a);
}