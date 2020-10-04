#include <iostream>
#include <stack>

int main() {
	int n = 0, a, b, m, t;
	scanf("%d %d %d", &a, &b, &m);

	for (int i = 0; i < m; ++i) {
		scanf("%d", &t);
		n *= a;
		n += t;
	}

	std::stack<int> s;
	while (n) {
		s.push(n % b);
		n /= b;
	}

	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
	printf("\n");
}