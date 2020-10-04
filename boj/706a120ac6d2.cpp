#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char input[1000000];
	cin.getline(input, 1000000);

	int count = 0;
	int i = 0;
	bool space = 1;
	while (input[i] != '\0') {
		if (input[i] == ' ') {
			space = 1;
		}
		else {
			if (space) {
				count++;
				space = 0;
			}
		}
		++i;
	}

	cout << count;
}