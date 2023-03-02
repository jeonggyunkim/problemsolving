#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll s[200000], l[200000], o[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, g, k;
	cin >> n >> g >> k;

	ll mx = -1;
	for (int i = 0; i < n; ++i) {
		cin >> s[i] >> l[i] >> o[i];
		mx = max(mx, l[i]);
	}

	ll low = 0, high = g + mx + 1;
	while (high - low != 1) {
		ll mid = (low + high) / 2;
		vector<ll> out;
		ll sum = 0;
		bool pos = 1;
		for (int i = 0; i < n; ++i) {
			if (o[i]) {
				out.push_back(s[i] * max(1LL, mid - l[i]));
			}
			else sum += s[i] * max(1LL, mid - l[i]);
			if (sum > g) {
				pos = 0;
				break;
			}
		}
		if (pos) {
			sort(out.begin(), out.end(), greater<ll>());
			for (int i = k; i < out.size(); ++i) {
				sum += out[i];
				if (sum > g) {
					pos = 0;
					break;
				}
			}
		}
		if (pos) low = mid;
		else high = mid;
	}
	cout << low;
}