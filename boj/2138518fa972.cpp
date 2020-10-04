#include <iostream>
using namespace std;

int ans[7] = {8, 7, 5, 2, 4, 9, 12};

int main() {
	char c;
	cin >> c;
	cout << ans[c - 'A'];
}