#include <iostream>
#include <cmath>
#define N 10000001
using namespace std;

int mindiv[N];
bool notprime[N];
int cnt[N];

int divcnt(int n) {
	if (cnt[n] > 0) return cnt[n];
	int ans = 1, suc = 0, last = n;
	while (n != 1) {
		if (mindiv[n] == last) suc++;
		else {
			ans *= suc + 1;
			last = mindiv[n];
			suc = 1;
		}
		n /= mindiv[n];
	}
	ans *= suc + 1;
	return cnt[n] = ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	notprime[0] = notprime[1] = 1;
	int sq = sqrt(N);
	for (int i = 2; i < N; ++i) {
		if (notprime[i]) continue;
		else {
			mindiv[i] = i;
			if (i < sq) {
				for (int j = i * i; j < N; j += i) {
					if (notprime[j] == 0) {
						notprime[j] = 1;
						mindiv[j] = i;
					}
				}
			}
		}
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int n, lo, hi;
		cin >> n >> lo >> hi;

		int ans = 0;
		for (int i = lo; i <= hi; ++i) {
			if (divcnt(i) == n) ans++;
		}
		cout << ans << '\n';
	}
}
