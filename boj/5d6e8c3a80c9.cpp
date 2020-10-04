#include <iostream>
using namespace std;

int main() {
	int C, R, K;
	cin >> C >> R >> K;

	if (K > C * R) {
		cout << 0 << endl;
		return 0;
	}

	int temp = 1;
	int x = 1;
	int y = 0;

	int dir = 0;
	int count = 0;
	int max = R;
	for (int i = 0; i < K; ++i) {
		if (dir == 0) {
			y++;
		}
		else if (dir == 1) {
			x++;
		}
		else if (dir == 2) {
			y--;
		}
		else {
			x--;
		}
		count++;
		if (count == max) {
			if (dir % 2 == 0) {
				C--;
				max = C;
			}
			else {
				R--;
				max = R;
			}
			count = 0;
			dir = (dir + 1) % 4;
		}
	}

	cout << x << " " << y << endl;

	return 0;
}