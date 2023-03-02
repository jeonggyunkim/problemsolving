#include <iostream>
#include <unordered_map>
#include <unordered_set>
#define MOD 1000000007
#define D 100000
#define LOC(x, y) (((x) << 20) | (y))
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int loc[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll x, y, p, q, t;
	unordered_map<ll, ll> mp;
	unordered_set<ll> jang;
	cin >> x >> y >> t;
	x += D; y += D;
	mp[LOC(x, y)] = 1;

	ll dest;
	cin >> p >> q;
	p += D; q += D;
	dest = LOC(p, q);

	ll ans = 0;
	int n;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		x += D; y += D;
		jang.insert(LOC(x, y));
	}

	for (int i = 0; i < t; ++i) {
		unordered_map<ll, ll> temp;
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			for (int k = 0; k < 4; ++k) {
				x = (it->first >> 20) + loc[k][0];
				y = (it->first & ((1 << 20) - 1)) + loc[k][1];
				if (abs(x - p) + abs(y - q) >= t - i) continue;
				ll now = LOC(x, y);
				if (now == dest) {
					(ans += it->second) %= MOD;
				}
				else if (!jang.count(now)) {
					temp[now] += it->second;
					temp[now] %= MOD;
				}
			}
		}
		mp = temp;
	}
	cout << ans;
}