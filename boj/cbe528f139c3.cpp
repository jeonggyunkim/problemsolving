#include <iostream>
using namespace std;

string s[4];

void cw(int i) {
	s[i] = s[i][7] + s[i].substr(0, 7);
}

void ccw(int i) {
	s[i] = s[i].substr(1, 7) + s[i][0];
}

void rotate_left(int i, int d) {
	if (i <= 0) return;
	if (s[i][6] != s[i - 1][2]) {
		rotate_left(i - 1, -d);
		if (d == 1) ccw(i - 1);
		else cw(i - 1);
	}
}

void rotate_right(int i, int d) {
	if (i >= 3) return;
	if (s[i][2] != s[i + 1][6]) {
		rotate_right(i + 1, -d);
		if (d == 1) ccw(i + 1);
		else cw(i + 1);
	}
}

int main() {
	for (int i = 0; i < 4; ++i) cin >> s[i];

	int n;
	cin >> n;

	int d, t;
	while (n--) {
		cin >> d >> t;
		d--;
		rotate_left(d, t);		
		rotate_right(d, t);
		if (t == 1) cw(d);
		else ccw(d);
	}
	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		if (s[i][0] == '1') ans += 1 << i;
	}
	cout << ans;
}