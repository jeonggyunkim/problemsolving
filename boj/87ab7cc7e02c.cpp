#include <iostream>
#include <set>
using namespace std;

int main() {
	int t;
	while (true) {
		scanf("%d", &t);
		if (t == -1) break;
		else {
			set<int> s;
			s.insert(t);
			while (scanf("%d", &t), t) s.insert(t);
			int count = 0;
			for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
				if (s.find(*it * 2) != s.end()) count += 1;
			}
			printf("%d\n", count);
		}
	}
}