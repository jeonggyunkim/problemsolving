#include <iostream>
using namespace std;

int main() {
	const char* alp = "abcdefghijklmnopqrstuvwxyz";
	char input[100];
	cin >> input;

	for (int i = 0; i < 26; i++) {
		int count = 0;
		int j = 0;
		while (input[j] != '\0') {
			if (input[j] == alp[i]) {
				count++;
			}
			j++;
		}
		cout << count << " ";
	}

	return 0;
}
