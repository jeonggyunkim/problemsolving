#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_set<string> s;
	int n;
	cin >> n;

	while (n--) {
		string str, real;
		cin >> str;
		bool in = 1, after = 0;
		for (int u: str) {
			if (u == '+') in = 0;
			else if (u == '@') {
				real += u;
				in = 1;
				after = 1;
			}
			else {
				if (after) real += u;
				else {
					if (u != '.' && in) real += u;
				}
			}
		}
		s.insert(real);
	}
	cout << s.size();
}