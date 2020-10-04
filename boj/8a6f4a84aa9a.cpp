#include <iostream>
#include <string>
#include <map>
using namespace std;

int p[200010];
int num[200010];

int find(int n) {
	if (n == p[n]) return n;
	return p[n] = find(p[n]);
}

int merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		p[b] = a;
		num[a] += num[b];
	}
	return num[a];
}

int main() {
	int TC, n;
	scanf("%d", &TC);
	for (int i = 0; i < TC; ++i) {
		map<string, int> m;
		char a[22];
		char b[22];
		int total = 0;

		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			scanf("%s %s", a, b);
			if (m.find(a) == m.end()) {
				p[total] = total;
				num[total] = 1;
				m[a] = total++;
			}
			if (m.find(b) == m.end()) {
				p[total] = total;
				num[total] = 1;
				m[b] = total++;
			}
			printf("%d\n", merge(m[a], m[b]));
		}
	}
	return 0;
}