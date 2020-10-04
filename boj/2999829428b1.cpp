#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	set<string> s;
	set<string> ans;

	char buf[21];
	while (n--) {
		scanf("%s", buf);
		s.insert(buf);
	}
	while (m--) {
		scanf("%s", buf);
		if (s.find(buf) != s.end()) ans.insert(buf);
	}

	printf("%d\n", ans.size());
	for (auto it = ans.begin(); it != ans.end(); ++it) printf("%s\n", (*it).c_str());
}