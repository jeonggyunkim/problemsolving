#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	char input[50][51];
	for (int i = 0; i < N; ++i) {
		cin >> input[i];
	}
	int len = 0;
	while (input[0][len] != 0) {
		len++;
	}
	for (int i = 0; i < len; ++i) {
		char c = input[0][i];
		bool b = true;
		for (int j = 1; j < N; ++j) {
			if (c != input[j][i]) {
				b = false;
				break;
			}
		}
		if (b) cout << c;
		else cout << '?';
	}
}