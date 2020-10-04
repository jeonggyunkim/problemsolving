#include <iostream>
#include <string>
using namespace std;

string s[14] = {"baby", "sukhwan", "tururu", "turu",
"very", "cute", "tururu", "turu",
"in", "bed", "tururu", "turu",
"baby", "sukhwan"};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;
	n--;

	if ((n % 14) % 4 == 2 || (n % 14) % 4 == 3) {
		t = n / 14 + 4 - (n % 14) % 4;
		cout << "tu";
		if (t < 5) while(t--) cout << "ru";
		else cout << "+ru*" << t;
	}
	else cout << s[n % 14];
}