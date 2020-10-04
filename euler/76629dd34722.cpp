#include <iostream>
using namespace std;

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	int now = 1, cnt = 0;
	for (int i = 1900; i <= 2000; ++i) {
		for (int j = 0; j < 12; ++j) {
			if (i != 1900 && now == 0) cnt++;
			now = (now + month[j]) % 7;
		}
	}

	cout << cnt << endl;
}