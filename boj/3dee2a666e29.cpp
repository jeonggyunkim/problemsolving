#include <iostream>
using namespace std;

int s[2] = {-8140, -7827}, n[2] = {27, 26};

int main() {
	int y = -8140, cnt = 813;
	for (int i = 0; i < 31; ++i) {
		int x = s[i % 2];
		for (int j = 0; j < min(cnt, n[i % 2]); ++j) {
			cout << x << ' ' << y << '\n';
			x += 626;
		}
		cnt -= n[i % 2];
		y += 542;
	}
	cout << "8134 8121";
}