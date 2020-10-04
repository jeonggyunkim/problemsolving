#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	for (int i = 0; i < 3; ++i) {
		cin >> a >> b >> c;
		int start = a * 3600 + b * 60 + c;
		cin >> a >> b >> c;
		int end = a * 3600 + b * 60 + c;
		cout << (end - start) / 3600 << ' ' << ((end - start) % 3600) / 60 << ' ' << (end - start) % 60 << '\n';
	}
}