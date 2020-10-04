#include <iostream>
using namespace std;

int main() {
	const char* alp = "abcdefghijklmnopqrstuvwxyz";
	char input[100];
	cin >> input;

	for (int i = 0; i < 26; i++) {
		int j = 0;
		while (input[j] != '\0') {
			if (input[j] == alp[i]) {
				cout << j << " ";
				break;
			}
			j++;
		}
		if (input[j] == '\0') {
			cout << -1 << " ";
		}
	}

	return 0;
}
