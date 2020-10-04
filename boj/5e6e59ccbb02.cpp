#include <iostream>
#include <string>
using namespace std;

int num, low, up, spe;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') num = 1;
		else if (s[i] >= 'a' && s[i] <= 'z') low = 1;
		else if (s[i] >= 'A' && s[i] <= 'Z') up = 1;
		else spe = 1;
	}

	cout << max(4 - num - low - up - spe, 6 - n);
}