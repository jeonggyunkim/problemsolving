#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	char op[20];
	deque<int> d;
	while (n--) {
		cin >> op;
		if (op[0] == 'p') {
			if (op[1] == 'u') {
				cin >> t;
				op[5] == 'f' ? d.push_front(t) : d.push_back(t);
			}
			else {
				if (op[4] == 'f') {
					cout << (d.empty() ? -1 : d.front()) << '\n';
					if (!d.empty()) d.pop_front();
				}
				else {
					cout << (d.empty() ? -1 : d.back()) << '\n';
					if (!d.empty()) d.pop_back();
				}
			}
		}
		else if (op[0] == 's') cout << d.size() << '\n';
		else if (op[0] == 'e') cout << d.empty() << '\n';
		else if (op[0] == 'f') cout << (d.empty() ? -1 : d.front()) << '\n';
		else cout << (d.empty() ? -1 : d.back()) << '\n';
	}
}