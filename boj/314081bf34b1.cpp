#include <iostream>
#include <deque>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);

	char op[100001];
	int n, t;

	while (tc--) {
		deque<int> d;
		scanf("%s", op);
		scanf("%d\n[", &n);

		for (int i = 0; i < n - 1; ++i)	{
			scanf("%d,", &t);
			d.push_back(t);
		}
		if (n != 0) {
			scanf("%d]", &t);
			d.push_back(t);
		}
		else scanf("]");

		bool front = 1;
		for (int i = 0;  op[i]; ++i) {
			if (op[i] == 'R') front = !front;
			else {
				if (d.empty()) {
					printf("error\n");
					goto brk;
				}
				if (front) d.pop_front();
				else d.pop_back();
			}
		}

		printf("[");
		if (front) {
			bool first = 1;
			for (auto it = d.begin(); it != d.end(); ++it) {
				if (first) first = 0;
				else printf(",");
				printf("%d", *it);
			}
		}
		else {
			bool first = 1;
			for (auto it = d.rbegin(); it != d.rend(); ++it) {
				if (first) first = 0;
				else printf(",");
				printf("%d", *it);
			}
		}
		printf("]\n");

		brk:;
	}
}