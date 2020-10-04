#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	char c;
	vector<int> prodN, prodP, powN, powP, divN, divP;
	int prodZ = 0, powZ = 0;
	while (n--) {
		cin >> c >> t;
		if (c == '*') {
			if (t > 0) prodP.push_back(t);
			else if (t < 0) prodN.push_back(-t);
			else prodZ++;
		}
		else if (c == '/') {
			if (t < 0) divN.push_back(-t);
			else divP.push_back(t);
		}
		else {
			if (t > 0) powP.push_back(t);
			else if (t < 0) powN.push_back(-t);
			else powZ++;
		}
	}
	sort(prodN.begin(), prodN.end());
	sort(prodP.begin(), prodP.end());
	sort(powN.begin(), powN.end());
	sort(powP.begin(), powP.end());
	sort(divN.begin(), divN.end());
	sort(divP.begin(), divP.end());

	long long ans = 0;
	if (powZ + powN.size() + powP.size() >= 2) ans++;
	if (prodZ + prodN.size() + prodP.size() >= 2) ans++;

	ans += 2LL * (long long)prodP.size() * divP.size();
	ans += 2LL * (long long)prodN.size() * divN.size();
	ans += (long long)powP.size() * prodN.size();
	ans += (long long)powN.size() * prodP.size();
	ans += (long long)powP.size() * divP.size();
	ans += (long long)powN.size() * divN.size();

	for (int u: powP) {
		auto it = lower_bound(prodP.begin(), prodP.end(), u);
		if (it != prodP.end() && *it == u) {
			ans++;
			it++;
		}
		ans += 2 * (prodP.end() - it);
	}

	for (int u: powN) {
		auto it = lower_bound(prodN.begin(), prodN.end(), u);
		if (it != prodN.end() && *it == u) {
			ans++;
			it++;
		}
		ans += 2 * (prodN.end() - it);
	}

	for (int u: powP) {
		int v = (int)(u * exp(2));
		v++;
		auto it = lower_bound(divN.begin(), divN.end(), v);
		ans += 2 * (divN.end() - it);
	}

	for (int u: powN) {
		int v = (int)(u * exp(2));
		v++;
		auto it = lower_bound(divP.begin(), divP.end(), v);
		ans += 2 * (divP.end() - it);
	}

	if (powZ) {
		ans += prodP.size() + prodN.size();
		ans += divP.size() + divN.size();
	}

	map<int, int> pos, neg;
	for (int u: prodP) pos[u]++;
	for (int u: powP) pos[u]++;
	for (int u: divP) pos[u]++;
	for (auto it = pos.begin(); it != pos.end(); ++it) if (it->second == 3) ans -= 2;

	for (int u: prodN) neg[u]++;
	for (int u: powN) neg[u]++;
	for (int u: divN) neg[u]++;
	for (auto it = neg.begin(); it != neg.end(); ++it) if (it->second == 3) ans -= 2;

	cout << ans;
}