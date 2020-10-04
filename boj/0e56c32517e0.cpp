#include <iostream>
using namespace std;

int arr[600000];
int st[10];

int main() {
	int ind = 0;
	for (int i = 1; i <= 100000; ++i) {
		int j = i;
		int cnt = 0;
		while (j) {
			st[cnt++] = j % 10;
			j /= 10;
		}
		while (cnt) {
			arr[ind++] = st[--cnt];
		}
	}

	int n, len = 0;
	cin >> n;
	int j = n;
	while (j) {
		len++;
		j /= 10;
	}
	for (int i = len - 1; i >= 0; --i) {
		st[i] = n % 10;
		n /= 10;
	}

	for (int i = 0; ; ++i) {
		bool ans = 1;
		for (int j = 0; j < len; ++j) {
			if (arr[i + j] != st[j]) {
				ans = 0;
				break;
			}
		}
		if (ans) {
			cout << i + 1;
			return 0;
		}
	}
}