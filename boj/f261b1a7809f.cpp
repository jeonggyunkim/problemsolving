#include <iostream>
using namespace std;

int main() {
	int s, k, h;
	cin >> s >> k >> h;
	if (s + k + h >= 100) cout << "OK";
	else {
		if (s < k && s < h) cout << "Soongsil";
		if (k < s && k < h) cout << "Korea";
		if (h < s && h < k) cout << "Hanyang";
	}
}