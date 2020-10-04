#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char name[101];
	cin >> name;

	cout << name[0];
	int i = 1;

	while (name[i]) {
		if (name[i] == '-') cout << name[i + 1];
		++i;
	}
}