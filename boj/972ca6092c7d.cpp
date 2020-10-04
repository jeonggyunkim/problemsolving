#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	int alp[26] = {};
	for (char u: s) {
		alp[u - 'a']++;
	}
	sort(alp, alp + 26);

	int ans = 0;
	for (int i = 0; i < 24; ++i) {
		ans += alp[i];
	}
	cout << ans;
}