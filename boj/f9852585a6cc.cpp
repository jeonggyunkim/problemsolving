#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int pos[4] = {0, 1, 2, 3};
	int a, b;
	while (n--) {
		cin >> a >> b;
		swap(pos[a], pos[b]);
	}

	for (int i = 1; i <= 3; ++i) if (pos[i] == 1) cout << i;
}