#include <iostream>
using namespace std;

bool left(char c) {
	const char* alp = "qwertyasdfgzxcvb";
	for (int i = 0; alp[i]; ++i) if (c == alp[i]) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int extra = 0;
	char t;
	int l = 0, r = 0;
	while ((t = getchar()) != -1 && t != '\n') {
		if (t == ' ') {
			extra++;
			continue;
		}
		else if (t >= 'A' && t <= 'Z') {
			extra++;
			t += 'a' - 'A';
		}
		if (left(t)) l++;
		else r++;
	}

	if (l > r) {
		if (l - r > extra) r += extra;
		else {
			extra -= l - r;
			r = l;
			l += (extra + 1) / 2;
			r += extra / 2;
		}
	}
	else {
		if (r - l > extra) l += extra;
		else {
			extra -= r - l;
			l = r;
			l += (extra + 1) / 2;
			r += extra / 2;
		}
	}

	cout << l << ' ' << r;
}