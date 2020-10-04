#include <iostream>
#include <set>
using namespace std;

int next(int n) {
	int ret = 0;
	while (n) {
		int l = n % 10;
		ret += l * l;
		n /= 10;
	}
	return ret;
}

int main() {
	int d;
	cin >> d;

	set<int> s;
	while (s.find(d) == s.end()) {
		s.insert(d);
		d = next(d);
		if (d == 1) {
			cout << "HAPPY";
			return 0;
		}
	}
	cout << "UNHAPPY";
}
