#include <iostream>
using namespace std;

bool tri[160000];

int main() {
	freopen("in", "rt", stdin);

	int num = 1, i = 2;
	while (num < 160000) {
		tri[num] = 1;
		num += i++;
	}

	int cnt = 0, now = 0;
	bool start = 0;
	char t;
	while ((t = getchar()) != -1) {
		if (t == '"') {
			if (start) {
				start = 0;
				if (tri[now]) cnt++;
				now = 0;
			}
			else start = 1;
		}
		else if (start) now += t - 'A' + 1;
	}
	cout << cnt << endl;
}