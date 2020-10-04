#include <iostream>
using namespace std;

int main() {

	char input[101];
	cin >> input;

	int i = 0;
	int count = 0;
	while (input[i] != '\0') {
		count++;
		if (input[i] == 'c') {
			if (input[i + 1] == '=') {
				i += 2;
				continue;
			}
			else if (input[i + 1] == '-') {
				i += 2;
				continue;
			}
		}
		else if (input[i] == 'd') {
			if (input[i + 1] == 'z') {
				if (input[i + 2] == '=') {
					i += 3;
					continue;
				}
			}
			else if (input[i + 1] == '-') {
				i += 2;
				continue;
			}
		}
		else if (input[i] == 'l') {
			if (input[i + 1] == 'j') {
				i += 2;
				continue;
			}
		}
		else if (input[i] == 'n') {
			if (input[i + 1] == 'j') {
				i += 2;
				continue;
			}
		}
		else if (input[i] == 's') {
			if (input[i + 1] == '=') {
				i += 2;
				continue;
			}
		}
		else if (input[i] == 'z') {
			if (input[i + 1] == '=') {
				i += 2;
				continue;
			}
		}
		++i;
	}

	cout << count;

	return 0;
}