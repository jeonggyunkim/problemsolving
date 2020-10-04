#include <iostream>
#include <stack>

int main() {
	long long n, i, j, r = 0;
	scanf("%lld", &i);

	if (i == 0) {
		printf("0\n");
		return 0;
	}

	while (i) {
		if (i > 0) {
			n = 1; j = 0;
			while (n < i) {
				n <<= 2; n += 1;
				j += 2;
			}
			i -= (1ll << j);
			r |= (1ll << j);
		}
		else {
			i = -i;
			n = 2; j = 1;
			while (n < i) {
				n <<= 2; n += 2;
				j += 2;
			}
			i = (1ll << j) - i;
			r |= (1ll << j);
		}
	}

	std::stack<char> s;
	while (r) {
		s.push(r & 1);
		r >>= 1;
	}

	while (!s.empty()) {
		printf("%c", s.top() + '0');
		s.pop();
	}
	printf("\n");
}