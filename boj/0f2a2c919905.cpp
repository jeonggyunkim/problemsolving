#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;

	set<int> next;
	for (int i = 2; i <= 7; ++i) {
		next.insert(i);
	}
	cout << "a1 ";

	char c = 'a';
	while (1) {
		if (c == 'h') {
			for (int i = 1; i < n; ++i) {
				cout << c << *next.begin() << ' ';
				next.erase(next.begin());
			}
			cout << "h8";
			break;
		}
		else {
			if (n <= 8) {
				for (int i = 2; i < n; ++i) {
					cout << c << *next.begin() << ' ';
					next.erase(next.begin());
				}
				cout << c << 8 << ' ';
				n = 1;
				c = 'h';
			}
			else {
				cout << c << 8 << ' ';
				while (next.size() != 1) {
					cout << c << *next.begin() << ' ';
					next.erase(next.begin());
				}
				int t = *next.begin();
				next.clear();
				for (int i = 1; i <= 7; ++i) {
					if (i != t) next.insert(i);
				}
				cout << c << t << ' ';
				if (n == 9) {
					c = 'h';
					cout << c << t << ' ';
				}
				else {
					c++;
					cout << c << t << ' ';
				}
				n -= 8;
			}
		}
	}
}