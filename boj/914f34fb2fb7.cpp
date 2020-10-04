#include <iostream>
#include <map>
using namespace std;

typedef pair<char, char> cc;

map<char, cc> m;

void front(char c) {
	if (c == '.') return;
	printf("%c", c);
	front(m[c].first);
	front(m[c].second);
}

void mid(char c) {
	if (c == '.') return;
	mid(m[c].first);
	printf("%c", c);
	mid(m[c].second);
}

void back(char c) {
	if (c == '.') return;
	back(m[c].first);
	back(m[c].second);
	printf("%c", c);
}

int main() {
	int n;
	scanf("%d", &n);
	char buf[3][2];
	for (int i = 0; i < n; ++i) {
		scanf("%s %s %s", buf[0], buf[1], buf[2]);
		m[buf[0][0]] = cc(buf[1][0], buf[2][0]);
	}
	front('A');
	printf("\n");
	mid('A');
	printf("\n");
	back('A');
	printf("\n");
}