#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int tc;
	cin >> tc;
	getchar();

	while (tc--) {
		string s, t, u;
		getline(cin, s);

		for (char v: s) {
			if (v != ' ') t += v;
		}

		vector<bool> rem(t.size());

		for (int i = 0; i < t.size(); ++i) {
			if (t[i] == '-' && t[i + 1] == '(') {
				rem[i + 1] = 1;
				int cnt = 1, j = i + 2;
				while (cnt) {
					if (t[j] == ')') cnt--;
					if (t[j] == '(') cnt++;
					if (cnt == 0) rem[j] = 1;
					j++;
				}
			}
			if (t[i] != '(' && t[i] != ')') rem[i] = 1;
		}

		for (int i = 0; i < t.size(); ++i) {
			if (rem[i]) u += t[i];
		}

		for (int i = 0; i < u.size(); ++i) {
			if (u[i] == '(' && u[i + 2] == ')') continue;
			if (u[i] == ')' && u[i - 2] == '(') continue;
			cout << u[i];
		}
		cout << '\n';
	}
}