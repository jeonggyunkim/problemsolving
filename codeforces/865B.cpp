#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;

	vector<ll> A(100000, 0), B(100000, 0);
	ll aSum = 0, bSum = 0;
	ll zero = 0;
	ll c, a, b;
	ll ans = 0, total = 0;
	for (int i = 0; i < n; ++i) {
		cin >> c >> a >> b;
		if (b > a) {
			B[b - a] += c;
			ans += c * b;
			bSum += c;
		}
		else if (a > b) {
			A[a - b] += c;
			ans += c * a;
			aSum += c;
		}
		else {
			zero += c;
			ans += c * a;
		}
		total += c;
	}
	if (total % s) zero += (s - total % s);

	ll aCnt = aSum % s;
	ll bCnt = bSum % s;
	if (s - aCnt > zero && s - bCnt > zero) {
		ll aSum = 0, bSum = 0;
		int ind = 0;
		while (aCnt) {
			if (A[ind] == 0) ind++;
			else {
				ll use = min(aCnt, A[ind]);
				aCnt -= use;
				aSum += use * ind;
				ind++;
			}
		}
		ind = 0;
		while (bCnt) {
			if (B[ind] == 0) ind++;
			else {
				ll use = min(bCnt, B[ind]);
				bCnt -= use;
				bSum += use * ind;
				ind++;
			}
		}
		if (aSum > bSum) ans -= bSum;
		else ans -= aSum;
	}
	cout << ans;
}