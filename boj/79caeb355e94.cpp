#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char op[10];
	int n, t;
	stack<int> st;
	cin >> n;

	while (n--) {
		cin >> op;
		if (op[0] == 'p' && op[1] == 'u') {
			cin >> t;
			st.push(t);
		}
		else if (op[0] == 'p') {
			cout << (st.empty() ? -1 : st.top()) << '\n';
			if (!st.empty()) st.pop();
		}
		else if (op[0] == 's') cout << st.size() << '\n';
		else if (op[0] == 'e') cout << st.empty() << '\n';
		else cout << (st.empty() ? -1 : st.top()) << '\n';
	}
}