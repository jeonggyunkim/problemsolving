#include <bits/stdc++.h>
#define N 250000
using namespace std;
	
typedef long long ll;
	
int fac[N + 1];
	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	fac[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fac[i] = ((ll)fac[i - 1] * i) % m;
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ll now = 1;
		(now *= (n - i + 1)) %= m;
		(now *= (n - i + 1)) %= m;
		(now *= fac[i]) %= m;
		(now *= fac[n - i]) %= m;
		(ans += now) %= m;
	}

	cout << ans;
}