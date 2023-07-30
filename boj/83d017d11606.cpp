#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int i, j, k, l, me;
	cin >> i >> j >> k >> l;

	vector<int> vec;
	for (int a = 1; a < 10; ++a)
		for (int b = 1; b < 10; ++b)
			for (int c = 1; c < 10; ++c)
				for (int d = 1; d < 10; ++d) {
					int num1 = 1000 * a + 100 * b + 10 * c + d;
					int num2 = 1000 * b + 100 * c + 10 * d + a;
					int num3 = 1000 * c + 100 * d + 10 * a + b;
					int num4 = 1000 * d + 100 * a + 10 * b + c;
					int clc = min({num1, num2, num3, num4});
					if (i == a && j == b && k == c && l == d) me = clc;
					vec.push_back(clc);
				}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < vec.size(); ++i) {
		if (me == vec[i]) cout << i + 1;
	}
}