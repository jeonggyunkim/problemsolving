#include <bits/stdc++.h>
using namespace std;
	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	if (n & 1) {
		cout << "No";
		return 0;
	}
	
	string s;
	cin >> s;
	
	int st = 0;
	bool chance = 1;
	for (char c: s) {
		if (c == '(') st++;
		else {
			if (st == 0) {
				if (chance) chance = 0;
				else {
					cout << "No";
					return 0;
				}
			}
			else {
				st--;
			}
		}
	}
	
	if (!chance) {
		if (st == 1) cout << "Yes";
		else cout << "No";
	}
	else {
		if (st) cout << "No";
		else cout << "Yes";
	}
}