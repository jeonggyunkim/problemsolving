#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	char input[102];
	int group = n;

	for (int i = 0; i < n; ++i) {
		cin >> input;
		bool count[26] = {};
		int j = 0;
		while (input[j] != '\0') {
			if (input[j] != input[j + 1]) {
				if (!count[input[j] - 97]) {
					count[input[j] - 97] = true;
				}
				else {
					group--;
					break;
				}
			}
			++j;
		}
	}

	cout << group;
}