#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt[10] = {};
	while (n) {
		cnt[n % 10]++;
		n /= 10;
	}

	if (cnt[3] || cnt[4] || cnt[5] || cnt[6] || cnt[7] || cnt[9]) cout << 0;
	else {
		if (cnt[2] && cnt[0] && cnt[1] && cnt[8]) {
			if (cnt[2] == cnt[0] && cnt[2] == cnt[1] && cnt[2] == cnt[8]) cout << 8;
			else cout << 2;
		}
		else cout << 1;
	}
}