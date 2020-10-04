#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> name;
	char num[100010][25];
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", num[i]);
		name[num[i]] = i;
	}
	char buf[25];
	int t;
	for (int i = 1; i <= m; ++i) {
		scanf("%s", buf);
		if (48 <= buf[0] && buf[0] < 58) {
			t = atoi(buf);
			printf("%s\n", num[t]);
		}
		else printf("%d\n", name[buf]);
	}
}
