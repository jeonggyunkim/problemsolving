#include <iostream>
#include <stack>
using namespace std;

int main() {
	char input[31];
	cin >> input;

	stack<int> s;
	for (int i = 0; input[i]; ++i) {
		if (input[i] == '(') s.push(-1);
		else if (input[i] == '[') s.push(-2);
		else {
			int sum = 0;
			while (!s.empty() && s.top() > 0) {
				sum += s.top();
				s.pop();
			}
			if (sum == 0) sum = 1;
			if (s.empty()) {
				cout << 0;
				return 0;
			}
			else {
				if (input[i] == ')') {
					if (s.top() == -2) {
						cout << 0;
						return 0;
					}
					else {
						s.pop();
						s.push(sum * 2);
					}
				}
				else {
					if (s.top() == -1) {
						cout << 0;
						return 0;
					}
					else {
						s.pop();
						s.push(sum * 3);
					}
				}
			}
		}
	}
	int ans = 0;
	while (!s.empty()) {
		if (s.top() < 0) {
			cout << 0;
			return 0;
		}
		else {
			ans += s.top();
			s.pop();
		}
	}
	cout << ans;
}