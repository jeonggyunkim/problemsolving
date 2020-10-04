#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int sub[10];
	bool change[10] = {};
	for (int i = 1; i <= 9; ++i) {
		cin >> sub[i];
		if (sub[i] >= i) change[i] = 1;
	}

	bool start = 1, con = 0;
	for (int i = 0; i < n; ++i) {
		int num = s[i] - '0';
		if (start) {
			if (sub[num] > num) {
				start = 0;
				con = 1;
				cout << sub[num];
			}
			else cout << num;
		}
		else {
			if (con) {
				if (sub[num] >= num) {
					cout << sub[num];
				}
				else {
					con = 0;
					cout << num;
				}
			}
			else cout << num;
		}
	}
}
