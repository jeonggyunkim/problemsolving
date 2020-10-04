#include <iostream>
using namespace std;

char op[5];

int main() {
	int a, b;
	int i = 1;
	while (scanf("%d %s %d", &a, op, &b)) {
		bool ans;
		switch (op[0]) {
			case 'E':
			return 0;
			case '=':
			ans = (a == b);
			break;
			case '!':
			ans = (a != b);
			break;
			case '>':
			ans = (op[1] ? (a >= b) : (a > b));
			break;
			case '<':
			ans = (op[1] ? (a <= b) : (a < b));
			break;
		}
		if (ans) printf("Case %d: true\n", i);
		else printf("Case %d: false\n", i);
		i++;
	}
}