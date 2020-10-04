#include <iostream>
using namespace std;

int arr[3][1010];

int main() {
	arr[0][0] = 1;
	arr[1][0] = 1;

	int cnt = 2, next = 2, len = 1;
	while (len < 1000) {
		arr[next][0] = 0;
		for (int j = 0; j < len; ++j) {
			arr[next][j] += arr[(next + 1) % 3][j] + arr[(next + 2) % 3][j];
			if (arr[next][j] >= 10) {
				arr[next][j] -= 10;
				arr[next][j + 1] = 1;
			}
			else arr[next][j + 1] = 0;
		}
		if (arr[next][len]) len++;
		next = (next + 1) % 3;
		cnt++;
	}
	cout << cnt << endl;
}