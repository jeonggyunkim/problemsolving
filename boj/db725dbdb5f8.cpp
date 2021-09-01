#include <iostream>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const ll A1 = 982384651, A2 = 999999893;
const ll B1 = 1032384667, B2 = 1000000007;

ll p1[2010], p2[2010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	p1[0] = p2[0] = 1;
	for (int i = 1; i <= 2000; ++i) {
		p1[i] = (p1[i - 1] * A1) % B1;
		p2[i] = (p2[i - 1] * A2) % B2;
	}

	int c, n;
	cin >> c >> n;

	unordered_set<ll> color, name;
	string s;
	while (c--) {
		cin >> s;

		ll h1 = 0, h2 = 0;
		for (int i = 0; i < s.size(); ++i) {
			h1 = ((h1 * A1) + s[i]) % B1;
			h2 = ((h2 * A2) + s[i]) % B2;
		}
		color.insert((h1 << 32) + h2);
	}
	while (n--) {
		cin >> s;

		ll h1 = 0, h2 = 0;
		for (int i = 0; i < s.size(); ++i) {
			h1 = ((h1 * A1) + s[i]) % B1;
			h2 = ((h2 * A2) + s[i]) % B2;
		}
		name.insert((h1 << 32) + h2);
	}

	int q;
	cin >> q;

	while (q--) {
		cin >> s;

		if (s.size() == 1) {
			cout << "No\n";
			continue;
		}

		bool pos = 0;
		ll head1 = 0, tail1 = 0;
		ll head2 = 0, tail2 = 0;
		for (int i = 0; i < s.size(); ++i) {
			tail1 = ((tail1 * A1) + s[i]) % B1;
			tail2 = ((tail2 * A2) + s[i]) % B2;
		}
		for (int i = 0; i < s.size() - 1; ++i) {
			head1 = (head1 * A1 + s[i]) % B1;
			head2 = (head2 * A2 + s[i]) % B2;
			tail1 -= (p1[s.size() - 1 - i] * s[i]) % B1;
			tail2 -= (p2[s.size() - 1 - i] * s[i]) % B2;
			if (tail1 < 0) tail1 += B1;
			if (tail2 < 0) tail2 += B2;

			if (color.count((head1 << 32) + head2) && name.count((tail1 << 32) + tail2)) {
				pos = 1;
				break;
			}
		}
		if (pos) cout << "Yes\n";
		else cout << "No\n";
	}
}