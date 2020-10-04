#include <iostream>
using namespace std;

bool start_pos[151];

int main() {	
	string s;
	cin >> s;

	int n = s.size();

	start_pos[0] = 1;
	for (int i = 0; i < n; ++i) {
		if (!start_pos[i]) continue;
		if (s[i] == '1') {
			if (i + 3 >= n || s[i + 1] != '0' || s[i + 2] != '0') continue;
			int j = i + 2;
			while (j < n && s[j] == '0') j++;
			while (j < n) {
				if (s[j] == '1') start_pos[j + 1] = 1;
				else break;
				j++;				
			}
		}
		else {
			if (i != n - 1 && s[i + 1] == '1') {
				start_pos[i + 2] = 1;
			}
		}
	}
	if (start_pos[n]) cout << "SUBMARINE";
	else cout << "NOISE";
}