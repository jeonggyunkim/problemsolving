#include <iostream>
#include <queue>
#define MOD 1000000007
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		ll n, t;
		cin >> n;

		priority_queue<ll, vector<ll>, greater<ll>> pq;
		while (n--) {
			cin >> t;
			pq.push(t);
		}
		ll ans = 1, a, b;
		while (pq.size() > 1) {
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			pq.push(a * b);

			a %= MOD;
			b %= MOD;
			(ans *= a) %= MOD;
			(ans *= b) %= MOD;
		}
		cout << ans << '\n';
	}
}