#include <iostream>
using namespace std;

int main() {
	int n, t;
	cin >> n;

	int young = 0, min = 0;
	while (n--) {
		cin >> t;
		young += (1 + t / 30) * 10;
		min += (1 + t / 60) * 15;
	}
	if (young < min) cout << "Y " << young;
	else if (young > min) cout << "M " << min;
	else cout << "Y M " << young;
}