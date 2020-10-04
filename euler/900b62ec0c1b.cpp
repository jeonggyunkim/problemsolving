#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int mo = 1, ja = 1;
	for (int i = 2; i <= 9; ++i) {
		for (int j = 1; j < i; ++j) {
			for (int t = 1; t < 10; ++t) {
				if (t == i || t == j) continue;
				int it = 10 * i + t, ti = 10 * t + i;
				int jt = 10 * j + t, tj = 10 * t + j;
				if (jt * i == it * j) ja *= jt, mo *= it;
				if (jt * i == ti * j) ja *= jt, mo *= ti;
				if (tj * i == it * j) ja *= tj, mo *= it;
				if (tj * i == ti * j) ja *= tj, mo *= ti;
			}
		}
	}
	cout << mo / __gcd(ja, mo) << endl;
}