#include <iostream>
using namespace std;

int word[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (char u: s) word[i] |= (1 << (u - 'a'));
	}

	int now = (1 << 26) - 1;
	while (m--) {
		char o, x;
		cin >> o >> x;
		x -= 'a';
		if (o == '1') {
			now &= ~(1 << x);
		}
		else {
			now |= (1 << x);
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if ((now | word[i]) == now) cnt++;
		}
		cout << cnt << '\n';
	}
}