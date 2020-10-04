#include <iostream>
using namespace std;

int main() {
	char input[1000001];
	scanf("%s", input);

	int count[26] = {};

	int i = 0;
	while (input[i] != '\0') {
		if (input[i] > 90) {
			count[input[i] - 97] += 1;
		}
		else {
			count[input[i] - 65] += 1;
		}
		++i;
	}

	int index = 0;
	int max = -1;
	bool overlap;
	for (int i = 0; i < 26; ++i) {
		if (count[i] > max) {
			max = count[i];
			index = i;
			overlap = 0;
		}
		else if (count[i] == max) {
			overlap = 1;
		}
	}
	if (overlap) cout << '?';
	else cout << (char)(index + 65);
}