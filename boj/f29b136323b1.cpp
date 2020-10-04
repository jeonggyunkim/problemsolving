#include <iostream>
#include <stack>
using namespace std;

int main() {
	char c[100003];
	scanf("%s", c);
	int n = -1;
	while (c[++n]);

	stack<char> s;
	int i = 0, cnt = 0;
	while (i < n) {
		if (c[i] == '(') {
			if (c[i + 1] == ')') {
				cnt += s.size();
				i += 2;
			}
			else {
				s.push('(');
				cnt++;
				i++;
			}
		}
		else {
			s.pop();
			i++;
		}
	}

	printf("%d\n", cnt);
}