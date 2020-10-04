#include <iostream>
#include <vector>
using namespace std;

int arr[9] = { 89, 145, 42, 20, 4, 16, 37, 58, 1 };

int cal(int n) {
	int r = 0;
	while (n) {
		r += (n % 10) * (n % 10);
		n /= 10;
	}
	return r;
}

bool in(int n) {
	for (int i = 0; i < 9; ++i) {
		if (n == arr[i]) return true;
	}
	return false;
}

int main() {
	int a, b;
	while (true) {
		scanf("%d %d", &a, &b);
		if (a + b == 0) break;
		printf("%d %d ", a, b);
		vector<int> aa;
		vector<int> bb;
		while (in(a) == false) {
			aa.push_back(a);
			a = cal(a);
		}
		while (in(b) == false) {
			bb.push_back(b);
			b = cal(b);
		}

		if (a == 1 ^ b == 1) {
			printf("0\n");
			continue;
		}

		if (a == b) {
			while (!aa.empty() && !bb.empty() && aa.back() == bb.back()) {
				aa.pop_back();
				bb.pop_back();
			}
			printf("%d\n", aa.size() + bb.size() + 2);
		}
		else {
			int ai, bi;
			for (int i = 0; i < 8; ++i) {
				if (a == arr[i]) ai = i;
			}
			for (int i = 0; i < 8; ++i) {
				if (b == arr[i]) bi = i;
			}
			int r = ai > bi ? ai - bi : bi - ai;
			printf("%d\n", aa.size() + bb.size() + 2 + (r > 4 ? 8 - r : r));
		}
	}

	return 0;
}