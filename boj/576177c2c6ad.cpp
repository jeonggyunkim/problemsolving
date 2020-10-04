#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, n;
	cin >> a >> b >> n;

	int t, m;
	char c;
	queue<int> sm, js;
	for (int i = 0; i < n; ++i) {
		cin >> t >> c >> m;
		for (int j = 0; j < m; ++j) {
			if (c == 'B') sm.push(t);
			else js.push(t);
		}
	}

	vector<int> sms, jss;
	int smf = 0, jsf = 0;
	int now = 0, num = 1;
	while (!sm.empty() || !js.empty()) {
		while (!sm.empty() && smf <= now && sm.front() <= now) {
			sm.pop();
			sms.push_back(num++);
			smf = now + a;
		}
		while (!js.empty() && jsf <= now && js.front() <= now) {
			js.pop();
			jss.push_back(num++);
			jsf = now + b;
		}
		now++;
	}

	cout << sms.size() << '\n';
	for (int u: sms) cout << u << ' ';
	cout << '\n';
	cout << jss.size() << '\n';
	for (int u: jss) cout << u << ' ';
}
