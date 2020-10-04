#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	set<string> name;
	char buf[100];
	char status[7];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s %s", buf, status);
		if (status[0] == 'e') name.insert(buf);
		else name.erase(buf);
	}
	set<string>::iterator it = name.end();
	do {
		--it;
		printf("%s\n", (*it).c_str());
	} while (it != name.begin());
}
