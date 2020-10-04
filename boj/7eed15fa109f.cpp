#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	char arr[100];

	for (int i = 0; i < n; ++i) {
		cin >> arr;
		int j = 0;
		int score = 0;
		int c = 1;
		while (arr[j] != '\0') {
			if (arr[j] == 'O') {
				score += c;
				c++;
			}
			else {
				c = 1;
			}
			++j;
		}
		cout << score << endl;
	}

	return 0;
}
