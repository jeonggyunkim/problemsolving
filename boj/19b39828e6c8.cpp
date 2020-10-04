#include <iostream>
#include <list>
using namespace std;

int main() {
	list<char> l;
	char c[100003];
	int i = 0;
	scanf("%s", c);
	while (c[i]) {
		l.push_back(c[i]);
		++i;
	}

	list<char>::iterator it = l.end();
	int n;
	scanf("%d", &n);

	char cc;
	for (i = 0; i < n; ++i) {
		getchar();
		cc = getchar();
		if (cc == 'P') {
			getchar();
			cc = getchar();
			it = l.insert(it, cc);
			it++;
		}
		else if (cc == 'B') {
			if (it != l.begin()) {
				--it;
				it = l.erase(it);
			}
		}
		else if (cc == 'L') {
			if (it != l.begin()) --it;
		}
		else {
			if (it != l.end()) ++it;
		}
	}

	for (it = l.begin(); it != l.end(); ++it) printf("%c", *it);
	printf("\n");
}