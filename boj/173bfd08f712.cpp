#include <iostream>
#include <algorithm>
using namespace std;

long long ink[500010], jum[500010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) cin >> ink[i];
	for (int i = 0; i < n; ++i) cin >> jum[i];

	for (int i = 0; i < n; ++i) {
		cout << upper_bound(jum + i, jum + n, ink[i]) - jum - i - 1 << ' ';
	}
}