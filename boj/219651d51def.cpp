#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	int n;
	cin >> n;
	char print[200001];
	int printi = 0;

	int now = 1, want;
	for (int i = 0; i < n; ++i) {
		cin >> want;
		if (now <= want) {
			for (; now <= want; ++now) {
				s.push(now);
				print[printi++] = '+';
			}
			s.pop();
			print[printi++] = '-';
		}
		else {
			if (s.empty() || s.top() != want) {
				cout << "NO";
				return 0;
			}
			s.pop();
			print[printi++] = '-';
		}
	}

	for (int i = 0; i < printi; ++i) {
		cout << print[i] << '\n';
	}
}