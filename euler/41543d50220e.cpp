#include <iostream>
using namespace std;

int main() {
	int ans = -1, len, b, p, t;
	int num[10];
	for (int i = 100; i < 1000; ++i) {
		for (int j = i; j < 1000; ++j) {
			int len = 0;
			b = 1;
			p = t = i * j;
			len = 0;
			while (t) { // 각 자릿수를 구하는 과정. n에는 길이가 저장됨
				num[len++] = t % 10;
				t /= 10;
			}
			for (int k = 0; k < len / 2; ++k) {
				if (num[k] != num[len - 1 - k]) b = 0;
			}
			if (b) ans = max(ans, p);
		}
	}
	cout << ans << endl;
}
