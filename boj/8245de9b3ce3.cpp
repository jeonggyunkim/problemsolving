#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;
	
	stack<int> s;
	int now = 1;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t == now) {
			now++;
			while (!s.empty() && s.top() == now) {
				s.pop();
				now++;
			}
		}
		else s.push(t);
	}
	if (s.empty()) cout << "Nice";
	else cout << "Sad";
}