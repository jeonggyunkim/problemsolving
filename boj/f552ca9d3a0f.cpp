#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	int p = 1;
	for (int i = 0; i < a.size(); ++i) {
		(p *= 2) %= MOD;
	}
	if (p) p = MOD - p;

	int anum = 0, bnum = 0;
	for (int i = 0; i < a.size(); ++i) {
		(anum *= 2) %= MOD;
		(bnum *= 2) %= MOD;
		if (a[i] == '1') {
			anum++;
			anum %= MOD;
		}
		if (b[i] == '1') {
			bnum++;
			bnum %= MOD;
		}
	}

	int cnt = 0;
	for (int i = 0; i < a.size(); ++i) {
		(bnum *= 2) %= MOD;
		if (b[i] == '1') {
			bnum += p;
			bnum++;
			bnum %= MOD;
		}
		if (anum == bnum) cnt++;
	}
	cout << cnt;
}