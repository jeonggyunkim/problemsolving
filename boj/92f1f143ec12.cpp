#include <iostream>
#include <list>
using namespace std;

int n = -1;
char a[26];
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
	scanf("%s ", a);
	while (a[++n]);

	while ((t = getchar()) != EOF) l.push_back(t);

	auto b = l.begin();
	auto e = l.end(); e--;
	auto it = b;

	bool front = true;
	while (it = e, !l.empty() && b != ++it) {
		if (front) {
			if (comp(b)) {
				bool over = false;
				for (int i = 0; i < n; ++i) {
					b = l.erase(b);
					if (b == e) over = true;
				}
				if (over) e = b;
				for (int i = 0; i < n; ++i) {
					if (b == l.begin()) break;
					b--;
				}
				front = !front;
			}
			else b++;
		}
		else {
			if (comp(e)) {
				for (int i = 0; i < n; ++i) e = l.erase(e);
				for (int i = 0; i < n; ++i) {
					if (b == l.begin()) break;
					b--;
				}
				front = !front;
			}
			else e--;
		}
	}

	for (auto it = l.begin(); it != l.end(); ++it) printf("%c", *it);
}