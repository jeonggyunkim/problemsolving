#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> iii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	while (cin >> n >> a >> b, n || a || b) {
		vector<iii> anear, bnear;
		int k, da, db;
		while (n--) {
			cin >> k >> da >> db;
			if (da < db) anear.push_back(make_tuple(db - da, da, k));
			else bnear.push_back(make_tuple(da - db, db, k));
		}

		sort(anear.begin(), anear.end(), greater<iii>());
		sort(bnear.begin(), bnear.end(), greater<iii>());

		int ans = 0;
		for (iii& u: anear) {
			int move = min(get<2>(u), a);
			a -= move;
			ans += move * get<1>(u);
			ans += (get<2>(u) - move) * (get<1>(u) + get<0>(u));
		}

		for (iii& u: bnear) {
			int move = min(get<2>(u), b);
			b -= move;
			ans += move * get<1>(u);
			ans += (get<2>(u) - move) * (get<1>(u) + get<0>(u));
		}

		cout << ans << '\n';
	}
}