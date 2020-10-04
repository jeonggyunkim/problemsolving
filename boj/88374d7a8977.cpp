#include <iostream>
#include <vector>
#include <algorithm>
#define min(a, b) (a > b ? b : a)
using namespace std;

vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int convert(int a, int b) {
	if (a == -1) return -1;

	int t = b, len = 1;
	while (a >= t) {
		a -= t;
		t *= b;
		len++;
	}

	vector<int> v;
	while (a) {
		v.push_back(a % b);
		a /= b;
	}
	while (v.size() < len) v.push_back(0);
	int r = 0;
	while (!v.empty()) {
		r *= 10;
		r += num[v.back()];
		v.pop_back();
	}
	return r;
}

int len(int n) {
	if (n == 0) return 1;
	int r = 0;
	while (n) {
		r++;
		n /= 10;
	}
	return r;
}

int main() {
	int n, m;
	int temp[10];
	scanf("%d %d", &n, &m);

	if (m == 10) {
		printf("%d", abs(n - 100));
		return 0;
	}
	for (int i = 0; i < m; ++i) scanf("%d", temp + i);
	sort(temp, temp + m);
	for (int i = m - 1; i >= 0; --i) num.erase(num.begin() + temp[i]);

	if (m == 9 && num[0] == 0) {
		printf("%d", min(abs(100 - n), n + 1));
		return 0;
	}

	int num = -1, t, pt = -1;
	while (true) {
		t = convert(num, 10 - m);
		if (t > n) break;
		pt = t;
		num++;
	}

	int a = abs(100 - n), b, c;
	if (pt != -1) b = n - pt + len(pt);
	else b = 1000000;
	c = t - n + len(t);

	printf("%d", min(a, min(b, c)));
}