#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int t, s;
	int sf = -1, p;
	for (int i = 0; i < n; ++i) {
		cin >> t >> s;
		if (s > sf) {
			sf = s;
			if (s == 0) p = 0;
			else if (s == 1 || s == 4) p = t + i * 20;
		}
	}
	cout << p;
}