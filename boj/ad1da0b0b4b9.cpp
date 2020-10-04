#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	char arr[100];
	while (tc--) {
		cin >> arr;
		stack<int> s;
		for (int j = 0; arr[j]; ++j) {
			if (arr[j] == '(') s.push(1);
			else {
				if (s.empty()) goto brk;
				s.pop();
			}
		}
		if (!s.empty()) {
			brk:
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
}