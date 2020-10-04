#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		char input[10001];
		cin >> input;

		stack<int> s;
		bool cor = 1;
		for (int i = 0; input[i]; ++i) {
			if (input[i] == '(' || input[i] == '{' || input[i] == '[') {
				s.push(input[i]);
			}
			else {
				if (!s.empty() && (input[i] - s.top() == 1 || input[i] - s.top() == 2)) s.pop();
				else {
					cor = 0;
					break;
				}
			}
		}
		if (s.empty() && cor) cout << "YES\n";
		else cout << "NO\n";
	}
}
