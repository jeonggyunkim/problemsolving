#include <iostream>
using namespace std;

long long one(unsigned long long t) {
	long long ret = (t + 1) / 2;
	for (int i = 1; i < 63; ++i) {
		ret += (t >> (i + 1)) * (1ULL << i);
		if (t & (1ULL << i)) {
			ret += (t & ((1ULL << i) - 1)) + 1;
		}
	}
	return ret;
}

int main() {
	unsigned long long a, b;
	cin >> a >> b;
	cout << one(b) - one(a - 1);
}