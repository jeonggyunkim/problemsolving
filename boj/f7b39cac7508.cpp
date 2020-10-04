#include <iostream>
#include <list>
using namespace std;

int n = -1;
char a[38];
list<char> l;

bool comp(list<char>::iterator it) {
	for (int i = 0; i < n; ++i) {
		if (it == l.end()) return false;
		if (*it != a[i]) return false;
		it++;
	}
	return true;
}

int main() {
	char t;
	while ((t = getchar()) != '\n') l.push_back(t);

	scanf("%s", a);
	while (a[++n]);

	auto it = l.begin();

	while (it != l.end()) {
		if (comp(it)) {
			for (int i = 0; i < n; ++i) it = l.erase(it);
			for (int i = 0; i < n; ++i) {
				if (it == l.begin()) break;
				it--;
			}
		}
		else it++;
	}

	if (l.empty()) printf("FRULA");
	else for (it = l.begin(); it != l.end(); ++it) printf("%c", *it);
}