#include <iostream>
#include <vector>
#include <map>
#define MOD 1000000007
using namespace std;

typedef pair<int, int> ii;

vector<ii> factorize(unsigned int n) {
	vector<ii> ret;
	if (n <= 1) return ret;
	if (n % 2 == 0) {
		int cnt = 0;
		while (n % 2 == 0) {
			cnt++;
			n /= 2;
		}
		ret.push_back(ii(2, cnt));
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			ret.push_back(ii(i, cnt));
		}
	}
	if (n != 1) ret.push_back(ii(n, 1));
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	int a, b;
	map<int, int> num, dom;
	while (n--) {
		cin >> a >> b;
		a = b - a;
		vector<ii> up = factorize(a);
		vector<ii> down = factorize(b);
		for (ii& u: up) num[u.first] += u.second;
		for (ii& u: down) dom[u.first] += u.second;
	}

	auto it = num.begin(), jt = dom.begin();
	long long up = 1, down = 1;
	while (it != num.end() && jt != dom.end()) {
		if (it->first == jt->first) {
			if (it->second < jt->second) {
				for (int i = 0; i < jt->second - it->second; ++i) (down *= it->first) %= MOD;
			}
			else {
				for (int i = 0; i < it->second - jt->second; ++i) (up *= it->first) %= MOD;
			}
			it++; jt++;
		}
		else {
			if (it->first > jt->first) {
				for (int i = 0; i < jt->second; ++i) (down *= jt->first) %= MOD;
				jt++;
			}
			else {
				for (int i = 0; i < it->second; ++i) (up *= it->first) %= MOD;
				it++;
			}
		}
	}
	while (it != num.end()) {
		for (int i = 0; i < it->second; ++i) (up *= it->first) %= MOD;
		it++;		
	}
	while (jt != dom.end()) {
		for (int i = 0; i < jt->second; ++i) (down *= jt->first) %= MOD;
		jt++;
	}
	cout << up << ' ' << down;
}